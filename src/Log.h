#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <string>
using namespace std;
class Log {
public:
	Log();
	virtual ~Log();
	void log(string path);

private:
	string path;
	void read_file();
	void time_stamp();
};

#endif
