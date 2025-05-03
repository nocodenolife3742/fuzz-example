#!/bin/bash -eu

make CXX="$CXX" CXXFLAGS="$CXXFLAGS"
cp html_parser $OUT/