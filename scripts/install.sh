#!/bin/bash

function installBazelTravis() {
    TMPDIR="${TMPDIR:-/tmp}"
    BAZEL_DEB="bazel_${BAZEL_VERSION}-linux-x86_64.deb"
    BAZEL_URL="https://github.com/bazelbuild/bazel/releases/download/${BAZEL_VERSION}/${BAZEL_DEB}"

    curl -sL --output "${TMPDIR}/${BAZEL_DEB}" "${BAZEL_URL}"
    sudo dpkg --force-all -i "${TMPDIR}/${BAZEL_DEB}"
    bazel --version
}

function installBazelLocal() {
    MAJOR_BAZEL_VERSION="$(echo ${BAZEL_VERSION} | cut -c 1,2,3)"
    URL="https://docs.bazel.build/versions/${MAJOR_BAZEL_VERSION}.0/install.html"

    if [[ ! "$(bazel --version 2>/dev/null)" =~ ${MAJOR_BAZEL_VERSION} ]]; then
        echo 2>"Please install bazel version >= ${MAJOR_BAZEL_VERSION}"
        echo 2>"Follow insttructions here: ${URL}"
    fi
}

# Main
if [ "${TRAVIS}" == "true" ]; then
    installBazelTravis
else
    installBazelLocal
fi
