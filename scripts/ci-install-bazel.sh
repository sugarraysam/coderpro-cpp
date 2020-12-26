#!/bin/bash

TMPDIR="${TMPDIR:-/tmp}"
BAZEL_DEB="bazel_${BAZEL_VERSION}-linux-x86_64.deb"
BAZEL_URL="https://github.com/bazelbuild/bazel/releases/download/${BAZEL_VERSION}/${BAZEL_DEB}"

curl -sL --output "${TMPDIR}/${BAZEL_DEB}" "${BAZEL_URL}"
sudo dpkg --force-all -i "${TMPDIR}/${BAZEL_DEB}"
bazel --version
