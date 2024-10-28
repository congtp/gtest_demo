#ifndef __LED_DRIVER_H__
#define __LED_DRIVER_H__

#include <stdint.h>

void LedDriver_Open(uint16_t *vitualLeds);
void LedDriver_Close(void);
void LedDriver_WriteLed(uint16_t *virtualLeds, uint16_t LedNo, uint8_t status);

#endif