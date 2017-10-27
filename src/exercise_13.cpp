//============================================================================
// Name        : exercise_13.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>

#include <dirent.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <string.h>

using namespace std;

/*
 * Formats a struct timespec into a buffer.
 */
int timespec2str(char *buf, uint len, struct timespec *ts) {
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

void show_folder_content(const char* path) {
	const uint TIME_FMT = strlen("2012-12-31 12:59:59.123456789") + 1;
	struct stat buf;
	char timespec[TIME_FMT];
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(path)) != NULL) {
		// print all the files and directories within directory
		printf("     name\t      size (bytes)\t   last modified\n");
		while ((ent = readdir(dir)) != NULL) {
			stat(ent->d_name, &buf);
			printf("%10s\t", ent->d_name);
			printf("%10ld bytes\t", buf.st_size);
			timespec2str(timespec, sizeof(timespec), &buf.st_mtim);
			printf("%10s\n", timespec);
		}
		closedir(dir);
	} else {
		// could not open directory
		perror("Could not open file");

	}
}

int main(int argc, char ** argv) {

const char* path = "/home/Tobias/workspace/exercise_13";
show_folder_content(path);
return 0;
}

