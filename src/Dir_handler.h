/*
 * Dirhandler.h
 *
 *  Created on: 27 Oct 2017
 *  Author: Tobias Valbjørn and Anders Reiche
 *
 *  Simple directory handler, that contains the implementation
 *  of the ls -la function.
 */

#ifndef DIR_HANDLER_H_
#define DIR_HANDLER_H_

#include<string>
#include <iostream>

using namespace std;

class Dir_handler {
public:

	/*The constructor should be initialized with the path to the directory
	 * you want to open.*/
	Dir_handler(string Path);
	virtual ~Dir_handler();
	/*The ls -la function*/
	void show_folder_content();
private:
	int timespec2str(char *buf, uint len, struct timespec *ts);
	string path;
};

#endif /* DIR_HANDLER_H_ */
