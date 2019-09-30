/**
 * @file NexHardware.h
 *
 * The definition of base API for using Nextion. 
 *
 * @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date    2015/8/11
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */
#ifndef __NEXHARDWARE_H__
#define __NEXHARDWARE_H__
#include <Arduino.h>
#include "NexConfig.h"
#include "NexTouch.h"

#define DEFAULT_TIMEOUT 1000
#define TRACE_MESSAGES false

extern bool nexTraceActive;
#if TRACE_MESSAGES
#define TRACE(a)            if (nexTraceActive) {a}
#define TRACE_Printf(...)   if (nexTraceActive) dbSerialPrintf(__VA_ARGS__)
#else
#define TRACE(a)            do{}while(0);
#define TRACE_Printf(...)   do{}while(0)
#endif
/**
 * @addtogroup CoreAPI 
 * @{ 
 */

/**
 * Init Nextion.  
 * 
 * @return true if success, false for failure. 
 */
bool nexInit(long baud = 9600, bool changeNextionBaudRate = true);

/**
 * Set Nextion BAUD rate
 * 
 */
void nexBAUD(long baud);

/**
 * Listen touch event and calling callbacks attached before.
 * 
 * Supports push and pop at present. 
 *
 * @param nex_listen_list - index to Nextion Components list. 
 * @return none. 
 *
 * @warning This function must be called repeatedly to response touch events
 *  from Nextion touch panel. Actually, you should place it in your loop function. 
 */
void nexLoop(NexTouch *nex_listen_list[]);

/**
 * @}
 */

bool recvRetNumber(uint32_t *number, uint32_t timeout = DEFAULT_TIMEOUT);
uint16_t recvRetString(char *buffer, uint16_t len, uint32_t timeout = DEFAULT_TIMEOUT);
void sendCommand(const char* cmd);
boolean sendCommandWait(const char* cmd, uint32_t timeout = DEFAULT_TIMEOUT);
bool recvRetCommandFinished(uint32_t timeout = DEFAULT_TIMEOUT);


void dumpMsg(char *strbuf, int strbuflen, byte *numbuf);
void parseRx(byte *p, int len);
boolean getEvent(byte *p);
boolean getResp(byte *p, uint32_t timeout = DEFAULT_TIMEOUT);
int getString(byte *p, int len, int timeout = DEFAULT_TIMEOUT);
boolean getNumber(byte *p, int timeout = DEFAULT_TIMEOUT);


#endif /* #ifndef __NEXHARDWARE_H__ */

