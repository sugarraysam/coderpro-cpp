#!/bin/bash

set -e

bazel coverage //...

if [ "${TRAVIS}" == "true" ]; then
    coveralls --lcov-file "bazel-out/_coverage/_coverage_report.dat" \
        --no-gcov \
        --extension "cc"
fi
