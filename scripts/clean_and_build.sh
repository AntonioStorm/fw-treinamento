#!/usr/bin/env bash
set -euo pipefail

BUILD_DIR="build"
DIST_DIR="dist"

# remove só se existir, e com segurança quanto à localização
rm -rf -- "$BUILD_DIR" "$DIST_DIR"
mkdir -p -- "$BUILD_DIR" "$DIST_DIR"

cd "$BUILD_DIR"

cmake -DPICOTOOL_FORCE_FETCH_FROM_GIT=1 ..

cmake --build . --parallel "$(nproc)"

echo "Build limpo concluído com sucesso."