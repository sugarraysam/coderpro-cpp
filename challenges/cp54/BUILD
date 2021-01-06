load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "cp54",
    srcs = ["phones.cc"],
    hdrs = ["phones.h"],
)

cc_test(
    name = "cp54_test",
    srcs = ["phones_test.cc"],
    deps = [
        ":cp54",
        "@com_google_googletest//:gtest_main",
    ],
)
