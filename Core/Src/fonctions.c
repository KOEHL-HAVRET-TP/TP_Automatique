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

/*void vitesse_moteur(){
	int i;
	int speed_value;
	for (i=0;i<6;i++){
		valeur_vitesse[i]=argv[0][6+i];
	}
	speed_value= atoi(valeur_vitesse);
	if(speed_value>Max_Pulse_Motor){
		speed_value=Max_Pulse_Motor;
	}
	TIM1->CCR1=speed_value*Max_Pulse_Motor/100;
	TIM1->CCR2=(100-speed_value)*Max_Pulse_Motor/100;



	sprintf(buffer_affichage_vitesse,"La valeur de la vitesse est : %d \r\n",speed_value);
	HAL_UART_Transmit(&huart2, buffer_affichage_vitesse, sizeof(buffer_affichage_vitesse), HAL_MAX_DELAY);

}*/




