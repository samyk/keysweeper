/* 
 * $Id: hid.c 88 2010-02-21 19:04:58Z ths $
 *
 * Microsoft keyboard specific Wireless Keyboard HID decoding
 *
 * Authors/Copyright:
 *    2009, Thorsten Schroeder <ths@dev.io>
 *
 * Revision: $Rev: 88 $
 *
 * Germany, Berlin, 2009/04/25
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
 *
 * */

#ifndef _HID2_H
#define _HID2_H

//#include <stdint.h>
#include <stdio.h>
#include "hid2.h"
#include "hidcodes.h"
//#define META_SHIFT   0x02

uint8_t hid_decode(uint8_t hid, uint8_t meta)
{
   if(hid >= sizeof(HID_basic)/2)
      return('_');

   /* return ASCII char - if the shift metakey is also pressed, there is one
    * bit set in the metakey info byte. */
   meta &= 0x22;
   return(HID_basic[hid][(meta>>5)||(meta>>1)]);
}


uint8_t hid_reverse(uint8_t c) 
{
   //printf("   [%02x] -> (%02x)\n", c, reverse_HID[c & 0xff]);
   return( reverse_HID[c & 0xff] );
}

//-----------------------------------------------------------------------------
// get appropriate meta key bitmask
//-----------------------------------------------------------------------------
uint8_t hid_metakey(uint8_t c)
{
   uint8_t ret = 0;
   uint8_t i = 0;
   
   for(i=0;i<255, HID_basic[i][1] != 0;i++) {
      if( c == HID_basic[i][1] )
         ret = META_SHIFT;
   }
   return ret;
}
#endif
