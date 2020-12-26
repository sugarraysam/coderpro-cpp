#!/bin/bash

bazel coverage //...

if [ "${TRAVIS}" == "true" ]; then
    coveralls --lcov-file "bazel-out/_coverage/_coverage_report.dat" \
        --no-gcov \
        --exclude tests \
        --extension "cc"
fi
