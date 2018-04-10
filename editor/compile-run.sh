#!/bin/bash
#




# ==================
# Global variables
# ==================

program=matrixEditor
src_file=matrixEditor.cpp

trace_file=trace.log

fltk_dir=fltk-1.3.4-2



# ==================
# Parse inpus args
# ==================

# Default behaviors
run_it=true
do_trace=false
debug=false

for arg in "$@"; do
    case $arg in
        -d) debug=true;;
        -r) run_it=false;;
        -t) do_trace=true;;
    esac
done



# ==================
# Install FLTK
# ==================

fltk_vers=1.3.4
fltk_tar=$fltk_dir-source.tar.gz

# Download tarball
if ! [[ -e $fltk_tar ]]; then
    wget http://fltk.org/pub/fltk/$fltk_vers/$fltk_tar;
fi

if ! [[ -d $fltk_dir ]]; then
    tar -xzf $fltk_tar;
fi

if ! [[ -d $fltk_dir/build ]]; then
    mkdir $fltk_dir/build;
    cd $fltk_dir;

    # Configure for local install
    ./configure --prefix=`pwd`/build --exec-prefix=`pwd`/build --enable-debug;
    make;

    # Generate documentation
    cd documentation;
    make html;
    cd ..;

    # Install the library under build/ and leave
    make install;
    cd ..;
fi



# ==================
# Compiling
# ==================

# Compilation programs
#
CC=g++
fltk_conf=$fltk_dir/build/bin/fltk-config

# Compilation flags
#
CPPFLAGS="-std=c++11 -Wall"
CPPFLAGS="$CPPFLAGS `./$fltk_conf --cxxflags --ldflags --use-images`"
if [[ $debug == true ]]; then
    CPPFLAGS="$CPPFLAGS -g3 -ggdb"
fi

# Compile the program
#
echo "$CC $CPPFLAGS $src_file -o $program;";
$CC $CPPFLAGS $src_file -o $program;

# Get the compilation status
compiling_return=$?


# Fltk 1.3.4-2
# -I/usr/local/include -I/usr/local/include/FL/images -I/usr/include/freetype2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT
# -L/usr/local/lib -lfltk_images -lpng -lz -lfltk_jpeg -lfltk -lXrender -lXfixes -lXext -lfontconfig -lpthread -ldl -lm -lX11

# Fltk 1.3.3
# -I/usr/local/include -I/usr/local/include/FL/images -I/usr/include/freetype2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT
# -L/usr/local/lib -lfltk_images -lpng -lz -lfltk_jpeg -lfltk -lXfixes -lXext -lfontconfig -lpthread -ldl -lm -lX11


# ==================
# Run
# ==================

if [[ $compiling_return == 0 && $run_it == true ]]; then
    if [[ $do_trace == true ]]; then
        strace ./$program |& tee $trace_file;
    else
        ./$program;
    fi
fi
