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

void ls_function(const char* path)
{

	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir (path)) != NULL) {
	  // print all the files and directories within directory
	  while ((ent = readdir (dir)) != NULL) {
	    printf ("%s\n", ent->d_name);
	  }
	  closedir (dir);
	} else {
	  // could not open directory
	  perror ("Could not open file");

	}


}

int main(int argc, char ** argv) {
	const char* path="/home/Tobias/workspace/exercise_13";
	ls_function(path);
	return 0;
}
