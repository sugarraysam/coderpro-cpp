load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "cp0",
    srcs = ["cp0.cc"],
    hdrs = ["cp0.h"],
)

cc_test(
    name = "cp0_test",
    srcs = ["cp0_test.cc"],
    deps = [
        ":cp0",
        "@com_google_googletest//:gtest_main",
    ],
)
