load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "cp53",
    srcs = ["stocks.cc"],
    hdrs = ["stocks.h"],
)

cc_test(
    name = "cp53_test",
    srcs = ["stocks_test.cc"],
    deps = [
        ":cp53",
        "@com_google_googletest//:gtest_main",
    ],
)
