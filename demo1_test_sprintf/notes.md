# TEST()
- The `TEST()` macro defines a function that is called when all tests are run.
- The first parameter is the name of a group of tests. The second parameter is the name of the test.

# ASSERT_EQ()
- The `ASSERT_EQ()` macro compare two integers, `sprintf()` should report that it formated a string of length three, and if it does, the `ASSERT_EQ()` succeeds.

# ASSERT_STREQ()
- The `ASSERT_STREQ()` macro compares two null-terminated strings. This statement declares that output should contain the string `"Hey"`

# How to run
```bash
    . ./project_setup.sh
    cmake ..
    make -j4
    ctest
```

# How to clean
```bash
    ./project_clean.sh
```

# Notes
- With those two tests, we can see the duplication into the test.
- There are duplicate output declarations, duplicate initializations, and duplicate overrun checks
- With just 2 tests, there is no big deal, but if you have many more tests, the duplication will be crowded out and obscure the code that is essential to understand the test case.
- That 's why the Test Fixture come into play
