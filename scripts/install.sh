#!/bin/bash

url="https://docs.bazel.build/versions/${BAZEL_VERSION}.0/install.html"
version="$(bazel --version 2>/dev/null)"

if [[ ! "${version}" =~ ${BAZEL_VERSION} ]]; then
    echo 2>"Invalid bazel version"
    echo 2>"Please install bazel v${BAZEL_VERSION} from ${url}"
fi
