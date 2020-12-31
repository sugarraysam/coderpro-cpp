load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "cp49",
    srcs = ["tree.cc"],
    hdrs = ["tree.h"],
)

cc_test(
    name = "cp49_test",
    srcs = ["tree_test.cc"],
    deps = [
        ":cp49",
        "@com_google_googletest//:gtest_main",
    ],
)
