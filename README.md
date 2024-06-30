# `cpp_plus_python`

A straightforward example of `pybind11` and `Current`.

Nontrivial pieces include:

1. Using C++17.
2. Confirming no memory leaks.

For C++17, explicitly setting the standard version in `CMakeLists.txt` did the job for MacOS. It worked out of the box on Ubuntu.

For memory leaks, the default test creates a 1GB string, and stores it thrice, with one character appended to it each time. This passes the tests when run as a GitHub action. Increasing the number of times the string is appended to and stored results in the test failing due to out-of-memory, ref. [this commit](https://github.com/dkorolev/cpp_plus_python/commit/d5fa8b40992323176627a2b034ab89c6a2735b65). Try locally for best results :-)

Also, I have tested it separately that, if not saved, the strings returned by C++ code are properly `free()`-d by the Python + `pybind11` combo. So, there are no memory leaks. Good!
