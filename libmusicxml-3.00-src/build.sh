#!/bin/bash

# url: http://wiki.bash-hackers.org/howto/getopts_tutorial
while getopts ":c:" opt; do
  case $opt in
    a)
      echo "-c was triggered, Parameter: $OPTARG" >&2
      NB_CORE_USED=$OPTARG
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit 1
      ;;
    :)
      echo "Option -$OPTARG requires an argument." >&2
      exit 1
      ;;
  esac
done

# build process
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX:PATH=. ../cmake
make -j$NB_CORE_USED
cd -
