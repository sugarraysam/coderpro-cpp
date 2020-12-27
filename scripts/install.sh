#!/bin/bash

set -e

function installBazelTravis() {
    TMPDIR="${TMPDIR:-/tmp}"
    BAZEL_DEB="bazel_${BAZEL_VERSION}-linux-x86_64.deb"
    BAZEL_URL="https://github.com/bazelbuild/bazel/releases/download/${BAZEL_VERSION}/${BAZEL_DEB}"

    curl -sL --output "${TMPDIR}/${BAZEL_DEB}" "${BAZEL_URL}"
    sudo dpkg --force-all -i "${TMPDIR}/${BAZEL_DEB}"
    bazel --version
}

function installBazelLocal() {
    BAZEL_MAJOR_VERSION="$(echo ${BAZEL_VERSION} | cut -c1)"
    URL="https://docs.bazel.build/versions/${BAZEL_MAJOR_VERSION}.0/install.html"

    if [[ ! "$(bazel --version 2>/dev/null)" == "${BAZEL_MAJOR_VERSION}*" ]]; then
        echo 2>"Please install a bazel version compatible with ${BAZEL_VERSION}"
        echo 2>"Follow insttructions here: ${URL}"
    fi
}

# Main
if [ "${TRAVIS}" == "true" ]; then
    installBazelTravis
else
    installBazelLocal
fi
