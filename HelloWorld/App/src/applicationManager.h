/*
 * applicationManager.h
 *
 *  Created on: Oct 3, 2020
 *      Author: PedroFernandes
 */

#ifndef APPLICATIONMANAGER_H_
#define APPLICATIONMANAGER_H_

#include "stm32h7xx_hal.h"
#include "applicationManager_Cfg.h"

class ApplicationManager {

private:
	//Variables
	UART_HandleTypeDef* huart;

	volatile uint8_t m_TxMsg[APPLLICATIONMANAGER_UART_MAXRCV_BYTES];
	volatile uint8_t m_RxMsg[APPLLICATIONMANAGER_UART_MAXRCV_BYTES];

	//APIs
	uint8_t sendMessage(uint8_t* Msg, const uint8_t size);
public:
	ApplicationManager(void);
	virtual ~ApplicationManager();

	void init(UART_HandleTypeDef* huart);
	void recvMessage(void);

	uint8_t executeMainFunction(void);

};

#endif /* APPLICATIONMANAGER_H_ */
