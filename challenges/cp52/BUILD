load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "cp51",
    srcs = ["intervals.cc"],
    hdrs = ["intervals.h"],
)

cc_test(
    name = "cp51_test",
    srcs = ["intervals_test.cc"],
    deps = [
        ":cp51",
        "@com_google_googletest//:gtest_main",
    ],
)
