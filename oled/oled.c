/*
 * oled.c
 *
 *  Created on: Apr 23, 2019
 *      Author: Lukas
 */
#include "oled.h"

char temperature[20];
char humidity[20];
char pressure[20];

void oled_init(void){
	ssd1306_initalization();
}
void oled_demo(void){

	ssd1306_clear_screen(0xFF);
	delay_ms(1000);
	ssd1306_clear_screen(0x00);
	delay_ms(1000);
	ssd1306_display_string(2, 0, "hello world", 12, 0);
	ssd1306_refresh_gram();
}

void oled_write_lines(char* data){
	sprintf(temperature,"temperatura  %.1f C", data[0]);
	sprintf(humidity,"wilgotnosc  %.1f %", data[1]);
	sprintf(pressure,"cisnienie  %.1f hPa", data[3]);

	ssd1306_display_string(2, 0, (uint8 *)temperature, 20, 1);
	ssd1306_display_string(2, 16, (uint8 *)humidity, 20, 1);
	ssd1306_display_string(2, 32, (uint8 *)pressure, 20, 1);
	ssd1306_refresh_gram();
}

//todo Lukas : replace delay in ssd sample

