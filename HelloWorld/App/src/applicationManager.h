/*
 * applicationManager.h
 *
 *  Created on: Oct 3, 2020
 *      Author: PedroFernandes
 */

#ifndef APPLICATIONMANAGER_H_
#define APPLICATIONMANAGER_H_

#include "stm32h7xx_hal.h"


class ApplicationManager {

private:
	//Variables
	UART_HandleTypeDef* huart;

	//APIs
	uint8_t sendMessage(uint8_t* Msg, const uint8_t size);
	uint8_t recvMessage(void);
public:
	ApplicationManager(UART_HandleTypeDef* huart);
	virtual ~ApplicationManager();

	uint8_t executeMainFunction(void);

};

#endif /* APPLICATIONMANAGER_H_ */
