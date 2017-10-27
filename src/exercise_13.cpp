//============================================================================
// Name        : exercise_13.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string>
#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <vector>

using namespace std;

const uint TIME_FMT = strlen("2012-12-31 12:59:59.123456789") + 1;
vector<const char *> filenames;
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

void get_folder_content(const char* path) {
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(path)) != NULL) {
		// print all the files and directories within directory
		while ((ent = readdir(dir)) != NULL) {
			filenames.push_back(ent->d_name);
		}
		closedir(dir);
	} else {
		// could not open directory
		perror("Could not open file");

	}

}

char * append(const char * string1, char * string2)
{
    char * result = NULL;
    asprintf(&result, "%s%s", string1, string2);
    return result;
}


void show_folder_content(struct stat *buf, const char* path) {

	char timespec[TIME_FMT];
	string folder_name=path;
	string temp;
	for (int i=0 ; i < filenames.size() ; i++) {
		string s =filenames[i];
		temp="";
		temp=folder_name+"/"+s;
		cout << temp << endl;
//		const char * temp2 = temp.c_str();
//		stat(temp2, buf);
//
//		printf("file: %s\t\t\t\t", temp2);
//		printf("Size: %ld bytes\t\t", buf->st_size);
//		timespec2str(timespec, sizeof(timespec), &buf->st_mtim);
//		printf("Time: %s\n", timespec);

	}
}

int main(int argc, char ** argv) {
	struct stat buf;

	const char* path = "/home/Tobias/workspace/exercise_13";
	get_folder_content(path);
	show_folder_content(&buf, path);
	return 0;
}

