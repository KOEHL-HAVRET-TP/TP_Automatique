/*
 * fonctions.c
 *
 *  Created on: Oct 21, 2022
 *      Author: alixh
 */

//includes
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fonctions.h"

//Variables

/**
* @brief  contient le prompt comme sur un shell linux
* */

void allumage(){
	HAL_GPIO_WritePin(ISO_RESET_GPIO_Port, ISO_RESET_Pin,1);
}





