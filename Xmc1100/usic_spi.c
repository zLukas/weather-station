/*
 * usic_spi.c
 *
 *  Created on: May 25, 2019
 *      Author: Lukas
 */


#include "usic_spi.h"
uint8 spi_init(void){
	SPI_MASTER_Init(&SPI_MASTER_0);
	SPI_MASTER_SetMode(&SPI_MASTER_0, XMC_SPI_CH_MODE_STANDARD);
	SPI_MASTER_SetBaudRate(&SPI_MASTER_0,10000);

}

uint8 usic_spi_send_read( uint8* data_to_send, uint8* data_to_read, uint8 data_send_count , uint8 data_read_count){

	SPI_MASTER_Transmit(&SPI_MASTER_0, data_to_send, data_send_count);
	while(SPI_MASTER_IsTxBusy(&SPI_MASTER_0));
	if(data_read_count !=0){
		//wait for receive
		//this delay is demanded, otherviwe it not read anything
		delay_ms(50);
		SPI_MASTER_Receive(&SPI_MASTER_0, data_to_read, data_read_count);
		while(SPI_MASTER_IsRxBusy(&SPI_MASTER_0));
	}
	return 0;

}

