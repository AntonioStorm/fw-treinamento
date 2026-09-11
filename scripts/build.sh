
#!/usr/bin/env bash
set -euo pipefail

BUILD_DIR="build"
DIST_DIR="dist"

# -p evita erro se a pasta já existir
mkdir -p "$BUILD_DIR" "$DIST_DIR"

cd "$BUILD_DIR"

cmake -DPICOTOOL_FORCE_FETCH_FROM_GIT=1 ..

# --build funciona com qualquer gerador (make, ninja, etc.)
cmake --build . --parallel "$(nproc)"

# copia os binários gerados para dist/ (ajuste conforme seu projeto)
# cp meu_binario ../dist/

echo "Build concluído com sucesso."