/*
 * eg915n.h
 *
 *  Created on: Dec 10, 2024
 *  Author: moshte
 */

#ifndef INC_EG915N_H_
#define INC_EG915N_H_
#include "main.h"
#include "string.h"
#include "stdlib.h"
#include "certs.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

#define RX_BUFFER_SIZE 128
#define dBUG 0
#define WRITECERTS 0
#define SND_ATCMD_TMOUT 2000
#define RETURN_RESPONSE_TMEOUT 1000

/*AT COMMANDS*/

int sendATCommand_new(char *cmd, uint32_t timeout, char *response) //Send by John for edition
{
    char local_rx_buf[128] = {'\0'};
    HAL_UART_Transmit(&huart1, cmd, strlen(cmd), 3000);

    uint32_t start_time = HAL_GetTick();
    uint32_t elapsed_time = 0;

    while(elapsed_time < timeout)
    {
    	uint8_t received_byte;
    	HAL_UART_Receive(&huart1, &received_byte, 1, 10);

    	//Append the byte in the buffer
    	strncat(local_rx_buf, (char*)&received_byte, 1);

    	//Check if the expected response is in the buffer
    	char*ptr = strtsr(local_rx_buf, response);
    	if(ptr != NULL)
    	{
    		return 0;
    	}
        elapsed_time = HAL_GetTick() - start_time;
    }

    if(dBUG)
    {
        char *ptr1 = strstr(local_rx_buf, "OK");
        char *ptr3 = strstr(local_rx_buf, "ERROR");
        if (ptr1 != NULL) {
                HAL_UART_Transmit(&huart2, local_rx_buf, strlen(local_rx_buf), 1000);
            }
        if (ptr3 != NULL) {
                HAL_UART_Transmit(&huart2, local_rx_buf, strlen(local_rx_buf), 1000);
            }
    }

    return 1;
}

uint8_t  SendATCommand_old(char *cmd, char *Response, uint32_t TimeOut) //Sends AT-commands and checks for errors and response matching without returning response
{
	char local_rx_buf[RX_BUFFER_SIZE] = {'\0'};
	HAL_UART_Transmit(&huart1, cmd, strlen(cmd), 3000);
	HAL_UART_Receive(&huart1, local_rx_buf, sizeof(local_rx_buf), Timeout);

	char *ptr = strstr(local_rx_buf, Response);

	if(dBUG)
	{
		char *ptr_ok = strstr(local_rx_buf, "OK");
		if(ptr_ok != NULL)
		{
			HAL_UART_Transmit(&huart3, local_rx_buf, strlen(local_rx_buf), 1000);
		}
		char *ptr_err = strstr(local_rx_buf, "ERROR");
		if(ptr_err != NULL)
		{
			HAL_UART_Transmit(&huart3, local_rx_buf, strlen(local_rx_buf), 1000);
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

char * ReturnResponse(char *cmd, uint32_t TimeOut) //Sends AT commands and returns response without checking errors and response matching
{
	char *local_tx_buf = (char *)malloc(200 * (sizeof(char)));

	HAL_UART_Transmit(&huart1, cmd, strlen(cmd), 1000 );
	if((HAL_UART_Receive(&huart1, local_tx_buf, strlen(local_tx_buf), 1000 )) != HAL_OK)
	{
		free(local_tx_buf);
		return NULL;
	}

	return local_tx_buf;
}



/*GNSS*/
void gnss_Init(void)
{
	char cmd_1[] = "AT+QGPSCFG=\"outport\",\"auxnmea\",115200";
	SendATCommand(cmd_1, "+QGPSCFG:", SND_ATCMD_TMOUT); //Config output port and baud

	char cmd_2[] = "AT+QGPSCFG=\"gnssconfig\",1";
	SendATCommand(cmd_2, "+QGPSCFG:", SND_ATCMD_TMOUT); //Config to GPS + GLONASS

	char cmd_3[] = "AT+QGPSCFG=\"nmeafmt\",1";
    SendATCommand(cmd_3, "+QGPSCFG:", SND_ATCMD_TMOUT); //Format(0 - Qualcomm, 1 - NMEA 0183)

    char cmd_4[] ="AT+QGPSCFG=\"gpsnmeatype\",1";
    SendATCommand(cmd_4, "+QGPSCFG:", SND_ATCMD_TMOUT); //Output type of GPS to GGA

    char cmd_5[] ="AT+QGPSCFG=\"glonassnmeatype\",0";
    SendATCommand(cmd_5, "+QGPSCFG:", SND_ATCMD_TMOUT); //Output type of GLONASS to disable

    char cmd_6[] ="AT+QGPS=1,3,0,10";
    SendATCommand(cmd_6, "+QGPS:", SND_ATCMD_TMOUT); //Turn on GPS

   	HAL_Delay(10000);
}

void gnss_GetLocation(char* Location, int* Lock)
{
	uint8_t retry = 0;
	char cmd[] = "AT+QGPSLOC?";
	char *rx_res= ReturnResponse(cmd, RETURN_RESPONSE_TMEOUT);
	while ((rx_res != NULL) && (retry != 3))
	{
		HAL_Delay(5000);
		retry++;
		rx_res= ReturnResponse(cmd, RETURN_RESPONSE_TMEOUT);
	}

	if(rx_res != NULL)
	{
		printf("Received %s\n", rx_res);
		HAL_UART_Transmit(&huart2, rx_res, Sizeof(rx_res), RETURN_RESPONSE_TMEOUT);

		char *ptr = strstr(rx_res, "+QGPSLOC");
		if(ptr != NULL)
		{
			char latitude[50] = {'\0'};
			char longitude[50] = {'\0'};

			char *token = strtok(rx_res, ",");
			token = strtok(NULL, ",");
			strcpy(latitude, token);

			token = strtok(NULL, ",");
			strcpy(longitude, token);

			sprintf(Location, "{\"Lat\":\"%s\",\"Lng\":\"%s\"}", latitude, longitude);
		free(rx_res);

			if(dBUG)
			{
				HAL_UART_Transmit(&huart2, "\r\n", sizeof("\r\n"), RETURN_RESPONSE_TMEOUT);
				HAL_UART_Transmit(&huart2, Location, sizeof(Location), RETURN_RESPONSE_TMEOUT);
				HAL_UART_Transmit(&huart2, "\r\n", sizeof("\r\n"), RETURN_RESPONSE_TMEOUT);
			}
	    *Lock = 1;
		}
	}
	else
	{
		sprintf(Location, "{\"Lat\": \"no fix\",\"Lng\": \"no fix\"}");
		*Lock = 0;
		printf("Location fetch failure");
	}

}

/*MQTT*/
void mqtt_Init(void)
{
	const int ca_cert_size = sizeof(CA_CRT);
	const int cl_cert_size = sizeof(SERVER_CERT);
	const int key_cert_size = sizeof(SERVER_KEY);

	HAL_Delay(5000);

	char cmd[50] = {'\0'};

	//CHECK IF IT'S ON
	sprintf(cmd, "ATI");
	SendATCommand(cmd, "OK", 200);

	//UPLOAD CA CERTIFICATE
	if(WRITECERTS)
	{
	sprintf(cmd, "AT+QFDEL=\"*\"" );
	SendATCommand(cmd, "OK", SND_ATCMD_TMOUT);

    //Open file
	sprintf(cmd, "AT+QFOPEN=\"ca_cert.pem\",1");
    SendATCommand(cmd, "OK", SND_ATCMD_TMOUT);

    char str[] = "AT+QFWRITE=2,";
    strcat(str, ca_cert_size);
    SendATCommand(str, "CONNECT", RETURN_RESPONSE_TMEOUT);
    SendATCommand(CA_CRT, "OK", 4000);

    sprintf(cmd, "AT+QFCLOSE=2");
    SendATCommand(cmd, "OK", SND_ATCMD_TMOUT);

    //List all file systems
    sprintf(cmd, "AT+QFLST=\"*\"");
    SendATCommand(cmd, "OK", SND_ATCMD_TMOUT);
	}

    //SET NETWORK
    sprintf(cmd, "AT+QCFG=\"nwscanmode\",0,1");
    SendATCommand(cmd, "+QCFG:", 300);

    sprintf(cmd, "AT+QCFG=\"band\",0003,8080004,1");
    SendATCommand(cmd, "+QCFG:", 300);

    HAL_Delay(1000);

    //PDP CONTEXT
    sprintf(cmd, "AT+QICSGP=1,1,\"safaricom\",\"saf\",\"data\",0");
    SendATCommand(cmd, "OK", 300);

    sprintf(cmd,"AT+QIACT=1", "OK");
    SendATCommand(cmd, "OK", RETURN_RESPONSE_TMEOUT);

    //CONFIGURE PATH FOR CERTIFICATES AND KEY FOR SSL CONTEXT ID 0
    sprintf(cmd,"AT+QSSLCFG=\"sslversion\",2,4", "OK");
    SendATCommand(cmd, "OK", RETURN_RESPONSE_TMEOUT);

    sprintf(cmd,"AT+QSSLCFG=\"cacert\",2,\"UFS:ca_cert.pem\"");
    SendATCommand(cmd, "OK", RETURN_RESPONSE_TMEOUT);

    sprintf(cmd,"AT+QSSLCFG=\"seclevel\",2,1");
    SendATCommand(cmd, "OK", RETURN_RESPONSE_TMEOUT);

    sprintf(cmd,"AT+QSSLCFG=\"ignorelocaltime\",2,1");
    SendATCommand(cmd, "OK", RETURN_RESPONSE_TMEOUT);

    sprintf(cmd,"AT+QSSLCFG=\"sni\",2,1");
    SendATCommand(cmd, "OK", RETURN_RESPONSE_TMEOUT);

    //CONFIGURE MQTT SESSION INTO SSL MODE FOR SSL CONTEXT ID 0
    sprintf(cmd,"AT+QMTCFG=\"version\",0,3");
    SendATCommand(cmd, "OK", RETURN_RESPONSE_TMEOUT);

    sprintf(cmd,"AT+QMTCFG=\"pdpcid\",0,1");
    SendATCommand(cmd, "OK", RETURN_RESPONSE_TMEOUT);

    sprintf(cmd,"AT+QMTCFG=\"ssl\",0,1,2");
    SendATCommand(cmd, "OK", RETURN_RESPONSE_TMEOUT);

    //CHECK IF NETWORK IS CONNECTED
    sprintf(cmd,"AT+CREG=1");
    SendATCommand(cmd, "OK", RETURN_RESPONSE_TMEOUT);

    HAL_Delay(1000);

}

int WaitForNetworkConnection(void)
{
	char cmd[50] = {'\0'};

	sprintf(cmd, "AT+CREG=1");
	SendATCommand(cmd, "OK", 300);

	sprintf(cmd, "AT+CREG?");
	char buff[] = ReturnResponse(cmd, 3000);
	if (buff == NULL)
		return 1;
	char* ptr_1 = strstr(buff, "+CREG: 1,1");
	char* ptr_2 = strstr(buff, "+CREG: 1,5");

	if (ptr_1 != NULL || ptr_2 != NULL)
	{
		printf("Network connected");
	}
	else
	{
		printf("Network not connected");
	}

}

#endif /* INC_EG915N_H_ */
