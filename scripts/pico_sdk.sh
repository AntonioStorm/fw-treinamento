#!/usr/bin/env bash
set -euo pipefail

SUBMODULE_PATH="3rdparty/pico-sdk"

git submodule sync --recursive
git submodule update --init --recursive "$SUBMODULE_PATH"

echo "OK: $SUBMODULE_PATH pronto."
git submodule status "$SUBMODULE_PATH"