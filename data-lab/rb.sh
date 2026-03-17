#!/usr/bin/env bash

set -e

make clean
make btest 2>/dev/null
chmod +x btest
./btest "$@"