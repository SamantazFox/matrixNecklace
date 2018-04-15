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
# Functions
# ==================

function verbose {
    if [[ $verbose == true ]]; then
        echo $@;
    fi
}

function show_help {
    echo "This utility downloads, builds, and installs locally matrixEditor, alongside with";
    echo "its dependencies, like the FLTK lirary.";
    echo "";
    echo "Supported options :";
    echo "";
    echo "  -d   Compile both FLTK and matrixEditor with debugging symbols";
    echo "  -f   Force a 'make clean' and a rebuild on FLTK library";
    echo "  -h   Display this help";
    echo "  -r   Run matrixEditor after compilation is it was sucessful";
    echo "  -t   Run matrixEditor through 'strace'. Needs '-r'";
    echo "  -v   Be verbose about what happens in the script";
}



# ==================
# Parse inpus args
# ==================

# Default behaviors
#
debug=false
force_rebuild=false
run_it=false
do_trace=false
verbose=false

# Parse commandline flags
#
for arg in "$@"; do
    case $arg in
        -d) debug=true;;
        -f) force_rebuild=true;;
        -h) show_help && exit;;
        -r) run_it=true;;
        -t) do_trace=true;;
        -v) verbose=true;;
    esac
done



# ==================
# Install FLTK
# ==================

fltk_vers=1.3.4
fltk_tar=$fltk_dir-source.tar.gz

# Download tarball and extract it if it's the first time
#
if ! [[ -e $fltk_tar ]]; then wget http://fltk.org/pub/fltk/$fltk_vers/$fltk_tar; fi
if ! [[ -d $fltk_dir ]]; then tar -xzf $fltk_tar; fi

# In case of force rebuild of FLTK
#
if [[ $force_rebuild == true ]]; then
    rm -rf $fltk_dir/build;
    make -C $fltk_dir clean;
fi

if ! [[ -d $fltk_dir/build ]]; then
    mkdir $fltk_dir/build;
    cd $fltk_dir;

    # Configure for local install
    CONFFLAGS="--prefix=`pwd`/build --exec-prefix=`pwd`/build --disable-xft"
    if [[ $debug == true ]]; then CONFFLAGS="$CONFFLAGS --enable-debug"; fi
    if ! [[ $verbose == true ]]; then CONFFLAGS="$CONFFLAGS --quiet"; fi
    verbose "./ configure $CONFFLAGS";

    make config.sub config.guess;
    ./configure $CONFFLAGS;
    make;

    # Generate html documentation, install the library under build/ and leave
    make -C documentation/ html;
    make install;
    cd ..;
fi



# ==================
# Compiling
# ==================

# Compilation programs
#
CXX=g++
FLC=$fltk_dir/build/bin/fltk-config

# Compilation flags
#
CXXFLAGS="-std=c++11 -Wall"
if [[ $debug == true ]]; then CXXFLAGS="$CXXFLAGS -g3 -ggdb"; fi
CXXFLAGS="$CXXFLAGS `./$FLC --cxxflags `"

CXXLIBS="`./$FLC --ldflags --use-images`"

# Compile the program
#
verbose "running $CXX $CXXFLAGS $src_file -o $program $CXXLIBS";
$CXX $CXXFLAGS $src_file -o $program $CXXLIBS;

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
