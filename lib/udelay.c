/*=============================================================================
Copyright (C) 2016 Kristina Brooks
All rights reserved.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

FILE DESCRIPTION
Simple timer based delay routine.

=============================================================================*/

#ifdef __arm__
	#include <stdint.h>
#else
	#include <common.h>
#endif

#include "../hardware.h"


void udelay(uint32_t t) {
	uint32_t tv = ST_CLO;
	for (;;) {
		/* nop still takes a cycle i think? */
		__asm__ __volatile__ ("nop" :::);
		if ((ST_CLO - tv) > t)
			return;
	}
}