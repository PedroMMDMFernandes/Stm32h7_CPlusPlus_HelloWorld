/*
 * applicationManager.cpp
 *
 *  Created on: Oct 3, 2020
 *      Author: PedroFernandes
 */

#include "applicationManager.h"
#include "string.h"



ApplicationManager::ApplicationManager(void)
{

}

ApplicationManager::~ApplicationManager() {
	// TODO Auto-generated destructor stub
}

void ApplicationManager::init(UART_HandleTypeDef* huart)
{
	this->huart = huart;
	memset((char*)m_RxMsg, '\0',APPLLICATIONMANAGER_UART_MAXRCV_BYTES);
	memset((char*)m_TxMsg, '\0',APPLLICATIONMANAGER_UART_MAXRCV_BYTES);
	strcpy((char*)m_TxMsg, "Hello");


	sendMessage((unsigned char*)m_TxMsg, APPLLICATIONMANAGER_UART_MAXRCV_BYTES);

	HAL_UART_Receive_IT(huart, (unsigned char*)m_RxMsg, APPLLICATIONMANAGER_UART_MAXRCV_BYTES);

    __HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);



#ifdef APPLLICATIONMANAGER_DEBUG
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
#endif
}

uint8_t ApplicationManager::sendMessage(uint8_t* Msg, const uint8_t size)
{
	uint8_t rtrnStatus = 0x00;
	uint8_t timeout = 0xff;

	HAL_UART_Transmit(huart, Msg, size, timeout);

	return rtrnStatus;
}

void ApplicationManager::recvMessage(void)
{

}


uint8_t ApplicationManager::executeMainFunction(void)
{
	uint8_t rtrnStatus = 0x00;
	uint8_t size = 0;

#ifdef APPLLICATIONMANAGER_DEBUG
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	HAL_Delay(1000);

	if(m_RxMsg[0] != '\0' )
	{
		size = strlen((const char*)m_RxMsg);
		strncpy((char*)m_TxMsg, (char*)m_RxMsg, size);
		sendMessage((unsigned char*)m_TxMsg, size);
		memset((unsigned char*)m_TxMsg, '\0', APPLLICATIONMANAGER_UART_MAXRCV_BYTES);
		memset((unsigned char*)m_RxMsg, '\0', APPLLICATIONMANAGER_UART_MAXRCV_BYTES);
		HAL_UART_Receive_IT(huart, (unsigned char*) m_RxMsg, APPLLICATIONMANAGER_UART_MAXRCV_BYTES);

	    huart->pRxBuffPtr  = (unsigned char*) m_RxMsg;
	    huart->RxXferSize  = APPLLICATIONMANAGER_UART_MAXRCV_BYTES;
	    huart->RxXferCount = APPLLICATIONMANAGER_UART_MAXRCV_BYTES;
	}

#endif

	return rtrnStatus;
}

