#include "LedDriver.h"

static uint16_t LedImage;

static error_code_t LedDriver_OutOfBoundsCheck(uint8_t LedNo)
{
    error_code_t err = LED_OK;
    if(LedNo < 1 || LedNo > 16)
        err = LED_OUT_OF_BOUNDS;
    return err;
}

void LedDriver_Open(uint16_t *virtualLeds)
{
    LedImage = ALL_LEDS_OFF;
    *virtualLeds = LedImage;
}

void LedDriver_Close(void)
{

}

void LedDriver_WriteLed(uint16_t *virtualLeds, uint8_t LedNo, uint8_t status)
{
    error_code_t err = LedDriver_OutOfBoundsCheck(LedNo);
    if(LED_OK != err)
        return;
    if(status)
    {
        LedImage |= LED_MASK(LedNo);
        *virtualLeds = LedImage;    
    }
    else
    {
        LedImage &= ~LED_MASK(LedNo);
        *virtualLeds = LedImage;
    }
}

void LedDriver_WriteAllLed(uint16_t* virtualLeds, uint8_t status)
{
    if(status)
    {
        LedImage = ALL_LEDS_ON;
        *virtualLeds = LedImage;
    }
    else
    {
        LedImage = ALL_LEDS_OFF;
        *virtualLeds = LedImage;
    }
}

LED_State_t LedDriver_ReadLed(uint16_t* virtualLeds, uint8_t LedNo)
{
    // Boundary check
    error_code_t err = LED_OK;
    if(LED_OK != err)
        return;
    
    LED_State_t ledState = LED_OFF;
    if((LedImage & LED_MASK(LedNo)))
        ledState = LED_ON;

    return  ledState;
}
