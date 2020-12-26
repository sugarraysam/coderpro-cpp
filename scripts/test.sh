#!/bin/bash

bazel coverage --instrument_test_targets \
    --experimental_cc_coverage \
    --combined_report=lcov \
    --coverage_report_generator=@bazel_tools//tools/test/CoverageOutputGenerator/java/com/google/devtools/coverageoutputgenerator:Main \
    //...

if [ "${TRAVIS}" == "true" ]; then
    coveralls --gcov "bazel-out/_coverage/_coverage_report.dat" \
        --gcov-options '\-lp' \
        --exclude tests \
        --include challenges \
        --extension ".cc"
fi
