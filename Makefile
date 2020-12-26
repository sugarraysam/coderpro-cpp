TARGETS := "install ci-install build test clean help"
.PHONY: $(TARGETS)

export BAZEL_VERSION := 3.7

install:
	@./scripts/install.sh

ci-install:
	@./scripts/ci-install-bazel.sh

build:
	@bazel build //...

# TODO add coverage report for coveralls
test:
	@bazel test //...

clean:
	@bazel clean

help:
	@echo "[ $(TARGETS) ]"
