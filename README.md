# CoderPro[![Build Status](https://www.travis-ci.com/sugarraysam/coderpro-cpp.svg?branch=main)](https://www.travis-ci.com/sugarraysam/coderpro-cpp) [![Coverage Status](https://coveralls.io/repos/github/sugarraysam/coderpro-cpp/badge.svg?branch=main)](https://coveralls.io/github/sugarraysam/coderpro-cpp?branch=main)

Solutions for [CoderPro](https://www.techseries.dev/products/coderpro) series. Walkthrough of popular interview questions in C++.

I provided a complexity analysis of both memory and time for every solution. I am not sharing the problems as this is a proprietary product.

This project is built using `C++17`, `Bazel` and `TravisCI`.

# Test

All tests live under the `tests/` directory. You can run all tests with coverage using:

```
$ make install
$ make test
```

# Resources

- [bazelbuild/bazel](https://github.com/bazelbuild/bazel)
- [google/googletest](https://github.com/google/googletest)
- [eddyxu/cpp-coveralls](https://github.com/eddyxu/cpp-coveralls)
- [Bazel default C++ toolchain config](https://github.com/bazelbuild/bazel/blob/master/tools/cpp/cc_toolchain_config.bzl)
- [.bazelrc format](https://docs.bazel.build/versions/master/guide.html#bazelrc)
