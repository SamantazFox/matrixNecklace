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

for arg in "$@"; do
    case $arg in
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
    ./configure --prefix=`pwd`/build --exec-prefix=`pwd`/build;
    make install;
fi



# ==================
# Compiling
# ==================

# Compilation programs
#
compiler=g++
cpp_vers=c++11
fltk_conf=$fltk_dir/build/bin/fltk-config

# Compilation flags
fltk_flags=`./$fltk_conf --cxxflags --ldflags --use-images`;

# Compile the program
$compiler -std=$cpp_vers -Wall $src_file $fltk_flags -s -o $program;

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
