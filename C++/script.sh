#!/bin/bash

set -e
BUILD_DIR="build"
EXEC_DIR="exec"

mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake -DENABLE_COVERAGE=ON ..

make -j$(nproc)

mkdir -p $EXEC_DIR

for exe in *; do
    if [ -f "$exe" ] && [ -x "$exe" ] && [ "$exe" != "tests" ]; then
        mkdir -p "$EXEC_DIR/$exe"
        mv "$exe" "$EXEC_DIR/$exe"
    fi
done

ctest
make coverage

./tests

cd coverage_html