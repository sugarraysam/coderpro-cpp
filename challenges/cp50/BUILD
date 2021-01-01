load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "cp50",
    srcs = ["substring.cc"],
    hdrs = ["substring.h"],
)

cc_test(
    name = "cp50_test",
    srcs = ["substring_test.cc"],
    deps = [
        ":cp50",
        "@com_google_googletest//:gtest_main",
    ],
)
