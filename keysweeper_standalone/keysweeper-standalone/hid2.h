/* 
 * $Id: hid.h 88 2010-02-21 19:04:58Z ths $
 *
 * Microsoft keyboard specific Wireless Keyboard HID tables
 *
 * Authors/Copyright:
 *    2008, Philip Schroedel 
 *    2008, Max Moser <mmo@remote-exploit.org>
 *    2009, Thorsten Schroeder <ths@dev.io>
 *    2010, Thorsten Schroeder <ths@dreamlab.net>
 *
 * Revision: $Rev: 88 $
 *
 * Switzerland, Winterthur, 2009/04/25
 * Germany, Berlin, 2009/04/25
 *
 *
 *   The contents of this file are subject to the Mozilla Public License
 *   Version 1.1 (the "License"); you may not use this file except in
 *   compliance with the License. You may obtain a copy of the License at
 *   http://www.mozilla.org/MPL/
 *
 *   Software distributed under the License is distributed on an "AS IS"
 *   basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 *   License for the specific language governing rights and limitations
 *   under the License.
 * 
 * */

#ifndef _HID_H
#define _HID_H
//#include <stdint.h>

#define META_SHIFT   0x02
#define META_WIN     0x08

uint8_t hid_decode(uint8_t, uint8_t);
uint8_t hid_reverse(uint8_t);
uint8_t hid_metakey(uint8_t);

#endif
