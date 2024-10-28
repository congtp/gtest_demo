#include "LedDriver.h"

static uint16_t LedImage;


void LedDriver_Open(uint16_t *vitualLeds)
{
    LedImage = 0;
    *vitualLeds = LedImage;
}

void LedDriver_Close(void)
{

}

void LedDriver_WriteLed(uint16_t *virtualLeds, uint16_t LedNo, uint8_t status)
{
    if(status)
    {
        LedImage |= (1 << (LedNo - 1));
        *virtualLeds = LedImage;    
    }
    else
    {
        LedImage &= ~(1 << (LedNo - 1));
        *virtualLeds = LedImage;
    }
}