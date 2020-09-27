#include "GPIO.h"
#include "../inc/MK20DX256.h"

static uint32_t RevMask;

void GPIO_Init(void){
	RevMask=BIT_TO_MASK(1)|BIT_TO_MASK(5);

	PORTC.PDDR=0x1012A000;
	PORTC.PSOR=0x10102000;
	PORTC.PCOR=0x00028000;

	return;
}

int8_t GPIO_SetPinAsOutput(uint8_t Pin){
	if(Pin>31){
		return GPIO_OUT_OF_RANGE;
	}
	PORTC.PDDR|=BIT_TO_MASK(Pin);
	return GPIO_OK;
}

int8_t GPIO_SetPinAsInput(uint8_t Pin){
	if(Pin>31){
		return GPIO_OUT_OF_RANGE;
	}
	PORTC.PDDR&=~(BIT_TO_MASK(Pin));
	return GPIO_OK;
}


int8_t GPIO_SetPin(uint8_t Pin){
	uint32_t Mask;

	if(Pin>31){
		return GPIO_OUT_OF_RANGE;
	}
	Mask=BIT_TO_MASK(Pin);
	if(!(PORTC.PDDR & Mask)){
		PORTC.PDDR |= Mask;
	}

	if(Mask & RevMask){
		PORTC.PCOR=Mask;
	}
	else{
		PORTC.PSOR=Mask;
	}
	return GPIO_OK;
}

int8_t GPIO_ClearPin(uint8_t Pin){
	uint32_t Mask;

	if(Pin>31){
		return GPIO_OUT_OF_RANGE;
	}

	Mask=BIT_TO_MASK(Pin);

	if(PORTC.PDDR & Mask){
		PORTC.PDDR &= ~Mask;
	}
	PORTC.PCOR=Mask;
	return GPIO_OK;
}

int8_t GPIO_ReadPin(uint8_t Pin){
	if(Pin>31){
		return GPIO_OUT_OF_RANGE;
	}
	return (PORTC.PDIR & BIT_TO_MASK(Pin))>>Pin;
}

uint32_t GPIO_ReadPort(void){
	uint32_t Mask;
	Mask= PORTC.PDDR;
	return PORTC.PDIR ^ RevMask;
}
