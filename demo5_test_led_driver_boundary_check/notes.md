# Test Boundary Conditions
- In some designs, the responsibility for assuring that no out-of-bounds params are controlled somewhere else.
- Boundary checks are the driver's responsibility.
- Test Boundary make sure any out-of-bounds params do not harm the system.

# Executable Reminders
- Let say the Out of bound can issue some error, but we can not decided what type of it
- So we can add an item to the test list, and comeback to do it later
- The google test provide the `DISABLED_` prefix to do this.



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
- The Four-Phases test pattern:
    - `Setup`: Establish the precondition to test
    - `Exercise`: Do something to the system
    - `Verify`: Check the expected outcome
    - `Cleanup`: Return the system under test to its initial state after the test.
