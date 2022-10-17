#!/bin/bash

if [ "$1" = "-c" ]
then
    rm -rf CMakeFiles
    rm cmake_install.cmake CMakeCache.txt Makefile runTests
    exit 0
elif [ "$1" = "-h" ]
then 
    echo "Help message:"
    echo "  -h -> Help message"
    echo "  -c -> Clean"
    exit 0
fi

cmake CMakeLists.txt

echo "/usr/bin/c++ -rdynamic CMakeFiles/runTests.dir/tests.cpp.o -o runTests  /usr/lib/libgtest.so.1.12.1 -lpthread -pthread" > CMakeFiles/runTests.dir/link.txt

make

