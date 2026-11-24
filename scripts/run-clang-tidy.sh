#!/bin/bash

set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

BUILD_DIR="$ROOT_DIR/build"

GCC_VERSION="16.1.0"
MINGW_GCC_ROOT="C:/ProgramData/mingw64/mingw64/lib/gcc/x86_64-w64-mingw32/$GCC_VERSION"

echo "Running Clang-Tidy..."

if [ ! -f "$BUILD_DIR/compile_commands.json" ]; then
    echo "ERROR: compile_commands.json not found!"
    echo "Build the project with CMAKE_EXPORT_COMPILE_COMMANDS enabled."
    exit 1
fi

clang-tidy \
    -p "$BUILD_DIR" \
    --extra-arg=-target \
    --extra-arg=x86_64-w64-windows-gnu \
    --extra-arg=-isystem \
    --extra-arg="$MINGW_GCC_ROOT/include/c++" \
    --extra-arg=-isystem \
    --extra-arg="$MINGW_GCC_ROOT/include/c++/x86_64-w64-mingw32" \
    --extra-arg=-isystem \
    --extra-arg="$MINGW_GCC_ROOT/include/c++/backward" \
    --extra-arg=-isystem \
    --extra-arg=C:/ProgramData/mingw64/mingw64/x86_64-w64-mingw32/include \
    --header-filter='src/.*' \
    src/main.cpp \
    src/Student.cpp \
    tests/test_student.cpp

echo "Clang-Tidy completed successfully!"
