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


void get_info(struct stat *buf, const char* path)
{


	stat(path,buf);

}

void show_stats(struct stat *buf, const char* path){

	printf("file: %s\n",path);
	printf("Size: %ld bits\n", buf->st_size);

}

int main(int argc, char ** argv) {
	struct stat buf;
	const char* path = "/home/Tobias/workspace/exercise_13/Debug/test.txt";

	get_info(&buf, path);
	show_stats(&buf,path);
	return 0;
}


