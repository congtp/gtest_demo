#include <gtest/gtest.h>
#include <cstdio>
#include <stdint.h>
extern "C" {
    #include "LedDriver.h"
}

typedef enum
{
    LED_OFF,
    LED_ON
}LED_State_t;

typedef enum{
    LED1 = 1,
    LED3,
    LED4,
    LED5,
    LED6,
    LED7,
    LED8,
    LED9,
    LED10,
    LED11,
    LED12,
    LED13,
    LED14,
    LED15,
    LED16,
}LED_number;

typedef enum{
    LED1_MASK = (1 << 0),
    LED2_MASK = (1 << 1),
    LED3_MASK = (1 << 2),
    LED4_MASK = (1 << 3),
    LED5_MASK = (1 << 4),
    LED6_MASK = (1 << 5),
    LED7_MASK = (1 << 6),
    LED8_MASK = (1 << 7),
    LED9_MASK = (1 << 8),
    LED10_MASK = (1 << 9),
    LED11_MASK = (1 << 10),
    LED12_MASK = (1 << 11),
    LED13_MASK = (1 << 12),
    LED14_MASK = (1 << 13),
    LED15_MASK = (1 << 14),
    LED16_MASK = (1 << 15),
}LED_MASK;

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


