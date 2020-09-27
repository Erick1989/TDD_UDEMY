#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define GPIO_OK 0
#define GPIO_OUT_OF_RANGE -1
#define NOT_IMPLEMENTED 99


int8_t GPIO_SetPinAsOutput(uint8_t Pin);
int8_t GPIO_SetPinAsInput(uint8_t Pin);
int8_t GPIO_SetPin(uint8_t Pin);
int8_t GPIO_ClearPin(uint8_t Pin);
int8_t GPIO_ReadPin(uint8_t Pin);
uint32_t GPIO_ReadPort(void);
void GPIO_Init(void);


#endif //GPIO_H

