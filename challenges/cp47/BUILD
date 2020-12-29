load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "cp47",
    srcs = ["clock.cc"],
    hdrs = ["clock.h"],
)

cc_test(
    name = "cp47_test",
    srcs = ["clock_test.cc"],
    deps = [
        ":cp47",
        "@com_google_googletest//:gtest_main",
    ],
)
