/*
 * applicationManager.cpp
 *
 *  Created on: Oct 3, 2020
 *      Author: PedroFernandes
 */

#include "applicationManager.h"
#include "applicationManager_Cfg.h"


ApplicationManager::ApplicationManager(UART_HandleTypeDef* huart)
: huart(huart)
{
	// TODO Auto-generated constructor stub
#ifdef APPLLICATIONMANAGER_DEBUG
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
#endif
}

ApplicationManager::~ApplicationManager() {
	// TODO Auto-generated destructor stub
}

uint8_t ApplicationManager::sendMessage(uint8_t* Msg, const uint8_t size)
{
	uint8_t rtrnStatus = 0x00;
	uint8_t timeout = 0x00;

	HAL_UART_Transmit(huart, Msg, size, timeout);

	return rtrnStatus;
}

uint8_t ApplicationManager::recvMessage(void)
{
	uint8_t rtrnStatus = 0x00;
	return rtrnStatus;
}


uint8_t ApplicationManager::executeMainFunction(void)
{
	uint8_t rtrnStatus = 0x00;

#ifdef APPLLICATIONMANAGER_DEBUG
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
#endif

	return rtrnStatus;
}

