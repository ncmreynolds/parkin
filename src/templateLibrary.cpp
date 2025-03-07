/*
 *	An Arduino library for parkin support
 *
 *	https://github.com/ncmreynolds/parkin
 *
 *	Released under LGPL-2.1 see https://github.com/ncmreynolds/parkin/LICENSE for full license
 *
 */
#ifndef parkin_cpp
#define parkin_cpp
#include "parkin.h"


parkinClass::parkinClass()	//Constructor function
{
}

parkinClass::~parkinClass()	//Destructor function
{
}

#if defined(ESP8266) || defined(ESP32)
void ICACHE_FLASH_ATTR parkinClass::begin()	{
#else
void parkinClass::begin()	{
#endif
	if(debug_uart_ != nullptr)
	{
		debug_uart_->println(F("parkin started"));
	}
}

#if defined(ESP8266) || defined(ESP32)
void ICACHE_FLASH_ATTR parkinClass::debug(Stream &terminalStream)
#else
void parkinClass::debug(Stream &terminalStream)
#endif
{
	debug_uart_ = &terminalStream;		//Set the stream used for the terminal
	#if defined(ESP8266)
	if(&terminalStream == &Serial)
	{
		  debug_uart_->write(17);			//Send an XON to stop the hung terminal after reset on ESP8266
	}
	#endif
}

#endif
