
#!/bin/bash

# Stop immediately if any command fails
set -euo pipefail

# Find project root
ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

echo "Running Clang-Tidy in CI..."

# Verify compilation database exists
if [ ! -f "$ROOT_DIR/build/compile_commands.json" ]; then
    echo "ERROR: compile_commands.json not found!"
    exit 1
fi

# Run Clang-Tidy and treat all reported warnings as errors
clang-tidy \
    -p "$ROOT_DIR/build" \
    --warnings-as-errors='*' \
    "$ROOT_DIR/src/Student.cpp"

echo "Clang-Tidy analysis completed successfully."
