#include "Log.h"

#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctime>


using namespace std;

Log::Log() {

}

Log::~Log() {

}

void Log::read_file() {
	/*We only want to read files. Not directories ie.*/
	size_t found = path.find(".txt");
	if (found == std::string::npos) {
		cout << "was not able to open the file for reading" << endl;
		throw(-5);
	}

	/*Read content of the file*/
	ifstream infile(path);
	if (infile.is_open()) {
		// we need a buffer, but don't know how big.
		infile.seekg(0, ios::end);
		long int len = infile.tellg();
		infile.seekg(0, ios::beg);

		char *buf = new char[len];
		infile.read(buf, len);

		infile.close();
		cout << "This was read from the file: " << endl << buf << endl;
		delete[] buf;
	}
}

void Log::time_stamp() {

	/*Write a time stamp*/
	ofstream outfile;
	outfile.open(path, std::ios_base::app);

	if (outfile.is_open()) {
		// current date/time based on current system
		time_t now = time(0);

		// convert to string form
		char* dt = ctime(&now);
		outfile << "\nDate and time for the last read: " << dt << endl;
	} else {
		cout << "was not able to open the file for writing" << endl;
		throw(-5);

	}
}

void Log::log(string str) {
	path = str;
	read_file();
	time_stamp();

}
