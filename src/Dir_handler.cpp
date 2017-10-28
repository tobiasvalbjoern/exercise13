/*
 * Dirhandler.cpp
 *
 *  Created on: 27 Oct 2017
 *      Author: Tobias Valbjørn and Anders Reiche.
 */
#include <dirent.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <string.h>
#include <string>

#include "Dir_handler.h"

Dir_handler::Dir_handler(string Path) {
	path = Path;

}

Dir_handler::~Dir_handler() {
	// TODO Auto-generated destructor stub
}

int Dir_handler::timespec2str(char *buf, uint len, struct timespec *ts) {
	/*
	 * grabbed from http://stackoverflow.com/questions/8304259/formattingstruct-
	 timespec
	 */
	int ret;
	struct tm t;
	tzset();
	if (localtime_r(&(ts->tv_sec), &t) == NULL) {
		return 1;
	}
	ret = strftime(buf, len, "%F %T", &t);
	if (ret == 0) {
		return 2;
	}
	len -= ret - 1;
	return 0;
}

void Dir_handler::show_folder_content() {

	struct stat buf;

	const uint TIME_FMT = strlen("2012-12-31 12:59:59.123456789") + 1;
	char timespec[TIME_FMT];

	DIR *dir;
	/*Our path is a string. We need to make a const char* to the opendir.*/
	const char* result = strcpy((char*)malloc(path.length()+1), path.c_str());
	if ((dir = opendir(result)) != NULL) {
		printf("     name\t      size (bytes)\t   last modified\n");

		/* For now we don't need the info from the stats.
		 * So there is no need to save them. If we wanted we could
		 * store the info from the stat in a linked list, return it.
		 * and use it in a different "metode" that displayed the info.
		 */
		struct dirent *ent;
		while ((ent = readdir(dir)) != NULL) {
			stat(ent->d_name, &buf);
			printf("%10s\t", ent->d_name);
			printf("%10ld bytes\t", buf.st_size);
			timespec2str(timespec, sizeof(timespec), &buf.st_mtim);
			printf("%10s\n", timespec);
		}
		free ((char*)result);
		closedir(dir);
	} else {
		// could not open directory
		perror("Could not open directory");
		throw(-4);
	}
}
