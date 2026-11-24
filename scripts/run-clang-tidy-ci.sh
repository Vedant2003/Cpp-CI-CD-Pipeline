
#!/bin/bash

set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

echo "Running Clang-Tidy in CI..."

if [ ! -f "$ROOT_DIR/build/compile_commands.json" ]; then
    echo "ERROR: compile_commands.json not found!"
    exit 1
fi

SOURCE_FILES=(
    "$ROOT_DIR/src/main.cpp"
    "$ROOT_DIR/src/Student.cpp"
    "$ROOT_DIR/tests/test_student.cpp"
)

clang-tidy \
    -p "$ROOT_DIR/build" \
    --header-filter='.*(/src/|/tests/).*' \
    --warnings-as-errors='*' \
    "${SOURCE_FILES[@]}"

echo "CI Clang-Tidy analysis completed successfully."
