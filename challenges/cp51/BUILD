load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "cp51",
    srcs = ["words.cc"],
    hdrs = ["words.h"],
)

cc_test(
    name = "cp51_test",
    srcs = ["words_test.cc"],
    deps = [
        ":cp51",
        "@com_google_googletest//:gtest_main",
    ],
)
