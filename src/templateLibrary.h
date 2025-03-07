/*
 *	An Arduino library for parkin support
 *
 *	https://github.com/ncmreynolds/parkin
 *
 *	Released under LGPL-2.1 see https://github.com/ncmreynolds/parkin/LICENSE for full license
 *
 */
#ifndef parkin_h
#define parkin_h
#include <Arduino.h>

class parkinClass	{

	public:
		parkinClass();														//Constructor function
		~parkinClass();														//Destructor function
		void begin();															//Start the parkin
		void debug(Stream &);													//Start debugging on a stream
	protected:
	private:
		Stream *debug_uart_ = nullptr;											//The stream used for the debugging
};
extern parkinClass parkin;	//Create an instance of the class, as only one is practically usable at a time
#endif
