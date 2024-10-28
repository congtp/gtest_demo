#include <gtest/gtest.h>
#include <cstdio>
#include <stdint.h>
extern "C" {
    #include "LedDriver.h"
}



// 1. Write the Test Suite
class LedDriverTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Dependency Injection
        LedDriver_Open(this->getVirtualLeds());
    }
    void TearDown() override
    {

    }
public:
    uint16_t *getVirtualLeds(void)
    {
        return &this->virtualLeds_;
    }
private:
    uint16_t virtualLeds_;
};


TEST_F(LedDriverTest, LedOffAfterInit)
{
    ASSERT_EQ((uint16_t)0, *(this->getVirtualLeds()));
}

TEST_F(LedDriverTest, TurnOnLedOne)
{
    // Setup
    
    // Exercise
    LedDriver_WriteLed((uint16_t*)this->getVirtualLeds(), LED1, LED_ON);

    // Verify
    // Virtual led should be 0x0001
    ASSERT_EQ((uint16_t)(LED1_MASK), *(this->getVirtualLeds()));

    // TearDown
}

TEST_F(LedDriverTest, TurnOffLedOne)
{
    // Setup

    // Exercise
    LedDriver_WriteLed((uint16_t*)this->getVirtualLeds(), LED1, LED_ON);
    LedDriver_WriteLed((uint16_t*)this->getVirtualLeds(), LED1, LED_OFF);

    // Verify
    ASSERT_EQ((uint16_t)0, *(this->getVirtualLeds()));
}

TEST_F(LedDriverTest, TurnOnMultipleLed)
{
    // Setup

    // Exercise
    LedDriver_WriteLed((uint16_t*)this->getVirtualLeds(), LED8, LED_ON);
    LedDriver_WriteLed((uint16_t*)this->getVirtualLeds(), LED9, LED_ON);
    
    // Verify
    ASSERT_EQ((uint16_t)0x180, *(this->getVirtualLeds()));
}

TEST_F(LedDriverTest, TurnOffAnyLed)
{
    // Setup

    // Exercise
    LedDriver_WriteLed((uint16_t*)this->getVirtualLeds(), LED8, LED_ON);
    LedDriver_WriteLed((uint16_t*)this->getVirtualLeds(), LED9, LED_ON);
    LedDriver_WriteLed((uint16_t*)this->getVirtualLeds(), LED9, LED_OFF);
    
    // Verify
    ASSERT_EQ((uint16_t)0x80, *(this->getVirtualLeds()));
}

TEST_F(LedDriverTest, TurnOnAllLed)
{
    // Setup

    // Exercise
    LedDriver_WriteAllLed((uint16_t*)this->getVirtualLeds(), LED_ON);
    
    // Verify
    ASSERT_EQ((uint16_t)0xffff, *(this->getVirtualLeds()));
}

TEST_F(LedDriverTest, TurnOffAllLed)
{
    // Setup

    // Exercise
    LedDriver_WriteAllLed((uint16_t*)this->getVirtualLeds(), LED_OFF);
    
    // Verify
    ASSERT_EQ((uint16_t)0, *(this->getVirtualLeds()));
}

TEST_F(LedDriverTest, LedMemoryIsNotReadable)
{
    *(this->getVirtualLeds()) = 0xffff;
    LedDriver_WriteLed((uint16_t*)this->getVirtualLeds(), LED8, LED_ON);
    ASSERT_EQ(0x80, *(this->getVirtualLeds()));
}

/**
 * Boundary check
 */
TEST_F(LedDriverTest, OutOfBoundDoesNoHarm)
{
    // Setup

    // Exercise
    LedDriver_WriteLed((uint16_t*)this->getVirtualLeds(), (LED_number)17, LED_ON);
    LedDriver_WriteLed((uint16_t*)this->getVirtualLeds(), (LED_number)-1, LED_ON);
    LedDriver_WriteLed((uint16_t*)this->getVirtualLeds(), (LED_number)3141, LED_ON);
    // Verify
    ASSERT_EQ((uint16_t)0, *(this->getVirtualLeds()));
}

/**
 * IGNORE_TEST
 */
TEST_F(LedDriverTest, DISABLED_OutOfBoundToDo)
{
    // This test will be ignored and won't run.
    EXPECT_EQ(1, 2);
}

TEST_F(LedDriverTest, IsOn)
{
    // Setup

    // Exercise
    // Assume the LED 9 is off
    ASSERT_EQ(LED_OFF, LedDriver_ReadLed((uint16_t*)this->getVirtualLeds(), LED9));
    // Turn on the led 9
    LedDriver_WriteLed((uint16_t*)this->getVirtualLeds(), LED9, LED_ON);
    
    // Verify that the LED 9 is turn on
    ASSERT_EQ(LED_ON, LedDriver_ReadLed((uint16_t*)this->getVirtualLeds(), LED9));
}


TEST_F(LedDriverTest, IsOff)
{
    // Setup

    // Exercise
    // Assume the LED 9 is off
    ASSERT_EQ(LED_OFF, LedDriver_ReadLed((uint16_t*)this->getVirtualLeds(), LED9));
    // Turn on the led 9
    LedDriver_WriteLed((uint16_t*)this->getVirtualLeds(), LED9, LED_ON);
    
    // Verify that the LED 9 is turn on
    ASSERT_NE(LED_OFF, LedDriver_ReadLed((uint16_t*)this->getVirtualLeds(), LED9));
}