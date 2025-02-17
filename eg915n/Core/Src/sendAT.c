/*
 * sendAT.c
 *
 *  Created on: Jan 23, 2025
 *      Author: moshte
 */
#include "sendAT.h"

char DMA_Rx_Buf[AT_BUFFER_LENGTH] = {'\0'} ;
char Loc_Buf[AT_BUFFER_LENGTH] = {'\0'};

void Eg_On(uint32_t TimeOn)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
	HAL_Delay(TimeOn);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);

	HAL_Delay(5000);
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if(huart->Instance == USART1)
	{
		 memcpy(Loc_Buf, DMA_Rx_Buf, AT_BUFFER_LENGTH);
	}
}

int SendATCommand(char *cmd, char *response, uint32_t Timeout)
{
   uint32_t pastTime = HAL_GetTick();
	HAL_UART_Transmit(&huart1, (uint8_t*)cmd, strlen(cmd), 3000);

    while(HAL_GetTick() - pastTime < Timeout)
    {
    	HAL_UARTEx_ReceiveToIdle_DMA(&huart1, (uint8_t*)DMA_Rx_Buf, sizeof(DMA_Rx_Buf));
    	__HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT);
    	char *ptr = strstr(Loc_Buf, response);
    	        if(dBUG)
    	        {
    	        	char *ptr_ok = strstr(Loc_Buf, "OK");
    	        	if(ptr_ok != NULL)
    	        	{
    	        		HAL_UART_Transmit(&huart3, (uint8_t*)Loc_Buf, strlen(Loc_Buf), 1000);
    	        	}
    	        	char *ptr_err = strstr(Loc_Buf, "ERROR");
    	        	if(ptr_err != NULL)
    	        	{
    	        		HAL_UART_Transmit(&huart3, (uint8_t*)Loc_Buf, strlen(Loc_Buf), 1000);
    	        	}
    	        }

    	    if(ptr != NULL)
    	    {
    	    	return 0;
    	    }
    	    else
    	    {
    	    	return 1;
    	    }
    }
    return 0;

}

uint8_t  SendATCommand_O(char *cmd, char *Response, uint32_t TimeOut)
{
	char local_rx_buf[AT_BUFFER_LENGTH] = {'\0'};
	HAL_UART_Transmit(&huart1, (uint8_t*)cmd, strlen(cmd), 3000);
	HAL_UART_Receive(&huart1, (uint8_t*)local_rx_buf, sizeof(local_rx_buf), TimeOut);

	char *ptr = strstr(local_rx_buf, Response);

	if(dBUG)
	{
		char *ptr_ok = strstr(local_rx_buf, "OK");
		if(ptr_ok != NULL)
		{
			HAL_UART_Transmit(&huart3, (uint8_t*)local_rx_buf, strlen(local_rx_buf), 1000);
		}
		char *ptr_err = strstr(local_rx_buf, "ERROR");
		if(ptr_err != NULL)
		{
			HAL_UART_Transmit(&huart3, (uint8_t*)local_rx_buf, strlen(local_rx_buf), 1000);
		}
	}

	if(ptr != NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}
