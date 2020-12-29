# CoderPro (Part 2) [![Build Status](https://www.travis-ci.com/sugarraysam/coderpro-cpp.svg?branch=main)](https://www.travis-ci.com/sugarraysam/coderpro-cpp) [![Coverage Status](https://coveralls.io/repos/github/sugarraysam/coderpro-cpp/badge.svg?branch=main)](https://coveralls.io/github/sugarraysam/coderpro-cpp?branch=main)

Solutions for [CoderPro](https://www.techseries.dev/products/coderpro) series. Walkthrough of popular interview questions in C++.

View [Part 1 in Python: `sugarraysam/coderpro-py`](https://github.com/sugarraysam/coderpro-py).

I provided a complexity analysis of both memory and time for every solution. I am not sharing the problems as this is a proprietary product.

This project is built using `C++17`, `Bazel` and `TravisCI`. It also uses the `GoogleTest` and `Abseil` libraries.

# Test

All tests live alongside the corresponding `*.cc` file under `challenges/`:

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
