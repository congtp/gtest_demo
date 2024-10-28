# Requirement of LED Driver
- The LED driver control 16 two-state LEDs
- The driver can turn on or off any individual LED without effect others
- The driver can turn all LEDs on or off with a single interface call.
- The user of the driver can query the state of any LED
- At power-on, the hardware default is for LEDs to be latched on.
They must be turned off by the software.
- LEDs are memory-mapped to a 16-bit word (at an address to be
determined).
- A 1 in a bit position lights the corresponding LED; 0 turns it off.
- The least significant bit corresponds to LED 1; the most significant
bit corresponds to LED 16

# Test List
## Driver Test List
- All LEDs are off after the driver is initialized.
- A single LED can be turned on.
- A single LED can be turned off.
- Multiple LEDs can be turned on/off .
- Turn on all LEDs
- Turn off all LEDs
- Query LED state
- Check boundary values
- Check out-of-bounds values

# How can we check the status of the hardware LED?
## Fake out the Driver
- The test can fake out the driver by passing the address of a bank of virtual LEDs instead of the real physical address.
- The virtual LEDs are nothing more than a variable with the same number of bits as the memory-mapped LEDs.
- The test case can set, reset, read the variable representing the virtual LEDs.

## Dependency Injection
- Passing the virtualLeds to the driver is a use of Dependency Injection
- Instead of the driver knowing and depending upon the LED's address at compiling time, we inject it at runtime.


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
