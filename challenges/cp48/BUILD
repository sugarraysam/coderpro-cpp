load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "cp48",
    srcs = ["stairs.cc"],
    hdrs = ["stairs.h"],
)

cc_test(
    name = "cp48_test",
    srcs = ["stairs_test.cc"],
    deps = [
        ":cp48",
        "@com_google_googletest//:gtest_main",
    ],
)
