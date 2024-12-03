# Amuse UTest

This is a unit test framework for Amuse.
Its main goal is to provide a simple way to test the Amuse codebase.

## Example of unit test

```c++
#include <amuse_utest/utest.hpp>

int add(int a, int b) {
    return a + b;
}

TEST(Addition, "Addition of two numbers") {
    ASSERT(add(1, 2) == 3);
    ASSERT(add(2, 3) == 5);
    ASSERT(add(3, 4) == 7);
}
```
