TARGETS := install test clean help
.PHONY: $(TARGETS)

export BAZEL_VERSION := 3.7.1

install:
	@./scripts/install.sh

test:
	@./scripts/test.sh

clean:
	@bazel clean --expunge

help:
	@echo "[ $(TARGETS) ]"
