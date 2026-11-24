
#!/bin/bash

set -euo pipefail

# Find project root
ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

echo "Running Clang-Tidy in CI..."

# Verify compilation database
if [ ! -f "$ROOT_DIR/build/compile_commands.json" ]; then
    echo "ERROR: compile_commands.json not found!"
    echo "Please configure CMake with -DCMAKE_EXPORT_COMPILE_COMMANDS=ON"
    exit 1
fi

# Find all project source and test files
SOURCE_FILES=(
    "$ROOT_DIR/src/main.cpp"
    "$ROOT_DIR/src/Student.cpp"
    "$ROOT_DIR/tests/test_student.cpp"
)

# Run Clang-Tidy and treat warnings as errors
clang-tidy \
    -p "$ROOT_DIR/build" \
    --header-filter='.*' \
    --warnings-as-errors='*' \
    "${SOURCE_FILES[@]}"

echo "CI Clang-Tidy analysis completed successfully."
