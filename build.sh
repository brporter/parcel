#!/bin/sh

mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
cp compile_commands.json ../
make test
cd ..
