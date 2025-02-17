/*
 * sendAT.h
 *
 *  Created on: Jan 27, 2025
 *  Author: moshte
 */

#ifndef INC_SENDAT_H_
#define INC_SENDAT_H_

#define INC_EG915N_H_
#include "main.h"
#include "string.h"
#include "stdlib.h"
#include <stdio.h>

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;
extern DMA_HandleTypeDef hdma_usart1_rx;

#define dBUG 1

enum buffer_lengths
{
   AT_BUFFER_LENGTH = 128
};

extern char DMA_Rx_Buf[AT_BUFFER_LENGTH];
extern char Loc_Buf[AT_BUFFER_LENGTH];

void Eg_On(uint32_t TimeOn);
int SendATCommand(char *cmd, char *response, uint32_t Timeout);
uint8_t  SendATCommand_O(char *cmd, char *Response, uint32_t TimeOut);

#endif /* INC_SENDAT_H_ */
