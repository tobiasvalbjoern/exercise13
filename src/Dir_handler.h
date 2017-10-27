/*
 * Dirhandler.h
 *
 *  Created on: 27 Oct 2017
 *      Author: Tobias
 */

#ifndef DIR_HANDLER_H_
#define DIR_HANDLER_H_

class Dir_handler {
public:
	Dir_handler(const char* Path);
	virtual ~Dir_handler();
	void show_folder_content();
private:
	int timespec2str(char *buf, uint len, struct timespec *ts);
	const char * path;
};

#endif /* DIR_HANDLER_H_ */
