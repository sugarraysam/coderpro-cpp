load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "cp52",
    srcs = ["intervals.cc"],
    hdrs = ["intervals.h"],
)

cc_test(
    name = "cp52_test",
    srcs = ["intervals_test.cc"],
    deps = [
        ":cp52",
        "@com_google_googletest//:gtest_main",
    ],
)
