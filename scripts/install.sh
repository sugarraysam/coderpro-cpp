#!/bin/bash

MAJOR_BAZEL_VERSION="$(echo ${BAZEL_VERSION} | cut -c 1,2,3)"
URL="https://docs.bazel.build/versions/${MAJOR_BAZEL_VERSION}.0/install.html"

if [[ ! "$(bazel --version 2>/dev/null)" =~ ${MAJOR_BAZEL_VERSION} ]]; then
    echo 2>"Please install bazel version >= ${MAJOR_BAZEL_VERSION}"
    echo 2>"Follow insttructions here: ${URL}"
fi
