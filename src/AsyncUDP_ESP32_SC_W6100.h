/****************************************************************************************************************************
  AsyncUDP_ESP32_SC_W6100.h

  AsyncUDP_ESP32_SC_W6100 is a Async UDP library for the ESP32_SC_W6100 (ESP32S2/S3/C3 + LwIP W6100)

  Based on and modified from ESPAsyncUDP Library (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncUDP_ESP32_SC_W6100
  Licensed under GPLv3 license

  Version: 2.1.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  2.1.0   K Hoang      10/01/2023 Initial coding for ESP32_SC_W6100
 *****************************************************************************************************************************/

#pragma once

#ifndef ASYNC_UDP_ESP32_SC_W6100_H
#define ASYNC_UDP_ESP32_SC_W6100_H

/////////////////////////////////////////////////////////////

#if ( ARDUINO_ESP32S2_DEV || ARDUINO_FEATHERS2 || ARDUINO_ESP32S2_THING_PLUS || ARDUINO_MICROS2 || \
      ARDUINO_METRO_ESP32S2 || ARDUINO_MAGTAG29_ESP32S2 || ARDUINO_FUNHOUSE_ESP32S2 || \
      ARDUINO_ADAFRUIT_FEATHER_ESP32S2_NOPSRAM )
	#if (_ASYNC_UDP_ESP32_SC_W6100_LOGLEVEL_ > 3)
		#warning Using ESP32_S2. To follow library instructions to install esp32-s2 core and WebServer Patch
		#warning You have to select HUGE APP or 1.9-2.0 MB APP to be able to run Config Portal. Must use PSRAM
	#endif

	#define USING_ESP32_S2        true

	#ifndef SHIELD_TYPE
		#define SHIELD_TYPE         "ESP32_S2_W6100"
	#endif

////////////////////////////////////////

#elif ( ARDUINO_ESP32C3_DEV )
	#if (_ASYNC_UDP_ESP32_SC_W6100_LOGLEVEL_ > 3)
		#if ( defined(ESP_ARDUINO_VERSION_MAJOR) && (ESP_ARDUINO_VERSION_MAJOR >= 2) )
		  #warning Using ESP32_C3 using core v2.0.0+. Either LittleFS, SPIFFS or EEPROM OK.
		#else
		  #warning Using ESP32_C3 using core v1.0.6-. To follow library instructions to install esp32-c3 core. Only SPIFFS and EEPROM OK.
		#endif

		#warning You have to select Flash size 2MB and Minimal APP (1.3MB + 700KB) for some boards
	#endif

	#define USING_ESP32_C3        true

	#ifndef SHIELD_TYPE
		#define SHIELD_TYPE         "ESP32_C3_W6100"
	#endif

////////////////////////////////////////

#elif ( defined(ARDUINO_ESP32S3_DEV) || defined(ARDUINO_ESP32_S3_BOX) || defined(ARDUINO_TINYS3) || \
        defined(ARDUINO_PROS3) || defined(ARDUINO_FEATHERS3) )
	#if (_ASYNC_UDP_ESP32_SC_W6100_LOGLEVEL_ > 3)
		#warning Using ESP32_S3. To install esp32-s3-support branch if using core v2.0.2-
	#endif

	#define USING_ESP32_S3        true

	#ifndef SHIELD_TYPE
		#define SHIELD_TYPE         "ESP32_S3_W6100"
	#endif

////////////////////////////////////////

#else
	#error This code is intended to run on the ESP32_S2/3, ESP32_C3 platform! Please check your Tools->Board setting.
#endif

/////////////////////////////////////////////////

#define BOARD_NAME      ARDUINO_BOARD

/////////////////////////////////////////////////

#if ( ( defined(ESP_ARDUINO_VERSION_MAJOR) && (ESP_ARDUINO_VERSION_MAJOR >= 2) ) && ( ARDUINO_ESP32_GIT_VER != 0x46d5afb1 ) )

	#if (_ASYNC_UDP_ESP32_SC_W6100_LOGLEVEL_ > 2)
		#warning Using code for ESP32 core v2.0.0+ in AsyncUDP_ESP32_SC_W6100.h
	#endif

	#define ASYNC_UDP_ESP32_SC_W6100_VERSION      "AsyncUDP_ESP32_SC_W6100 v2.1.0 for core v2.0.0+"

	extern "C"
	{
		#include "lwip/ip_addr.h"
		#include "freertos/queue.h"
		#include "freertos/semphr.h"
	}

#else

	#if (_ASYNC_UDP_ESP32_SC_W6100_LOGLEVEL_ > 2)
		#warning Using code for ESP32 core v1.0.6- in AsyncUDP_ESP32_SC_W6100.h
	#endif

	#define ASYNC_UDP_ESP32_SC_W6100_VERSION      "AsyncUDP_ESP32_SC_W6100 v2.1.0 for core v1.0.6-"

	extern "C"
	{
		#include "lwip/ip_addr.h"
		#include <tcpip_adapter.h>
		#include "freertos/queue.h"
		#include "freertos/semphr.h"
	}
#endif

#include "IPAddress.h"
#include "IPv6Address.h"
#include "Print.h"
#include <functional>

////////////////////////////////////////////////

#include <WebServer_ESP32_SC_W6100.h>     // https://github.com/khoih-prog/WebServer_ESP32_SC_W6100

#include "AsyncUDP_ESP32_SC_W6100_Debug.h"

#include "AsyncUDP_ESP32_SC_W6100.hpp"
#include "AsyncUDP_ESP32_SC_W6100_Impl.h"

////////////////////////////////////////////////

#endif    //ASYNC_UDP_ESP32_SC_W6100_H
