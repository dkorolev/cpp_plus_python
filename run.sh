#!/bin/bash

set -e

[ -d pybind11 ] || (echo 'Cloning pybind11.'; git clone https://github.com/pybind/pybind11.git)
[ -d current ] || (echo 'Cloning current.'; git clone https://github.com/c5t/current.git)

echo
echo -n 'Testing Python3: '
echo 'print("OK")' | python3
echo

cmake -B build

echo

cmake --build build

echo
echo 'Build successful, now running some Python.'
echo

cat test.py | (cd build; python3)

echo
echo 'Script successful.'
