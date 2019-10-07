@echo off

IF NOT EXIST build MKDIR build

pushd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
msbuild parcel.sln
popd