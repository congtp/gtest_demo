#ifndef __LED_DRIVER_H__
#define __LED_DRIVER_H__

#include <stdint.h>

#define ALL_LEDS_ON (0xffff)
#define ALL_LEDS_OFF (0x0000)

typedef enum
{
    LED_OUT_OF_BOUNDS = -1,
    LED_OK = 0,
}error_code_t;

typedef enum
{
    LED_OFF,
    LED_ON
}LED_State_t;

typedef enum{
    LED1 = 1,
    LED2,
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

#define LED_MASK(LedNo) (1 << (LedNo - 1))


void LedDriver_Open(uint16_t *virtualLeds);
void LedDriver_Close(void);
void LedDriver_WriteLed(uint16_t *virtualLeds, uint8_t LedNo, uint8_t status);
void LedDriver_WriteAllLed(uint16_t* virtualLeds, uint8_t status);
LED_State_t LedDriver_ReadLed(uint16_t* virtualLeds, uint8_t LedNo);

#endif