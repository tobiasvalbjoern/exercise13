//============================================================================
// Name        : exercise_13.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <vector>

#include "OptChars.h"
#include "OptWord.h"
#include "Options.h"
#include "FileHandler.h"
#include "Dir_handler.h"

using namespace std;
FileHandler fileobj;

void case_log(int argc, const char** argv, int i);
void case_file(int argc, const char** argv, int i);

int main(int argc, const char ** argv) {
	try {
		int WordArgs = 0;
		string validOpt = "abof";
		vector<string> validWords { "log", "help", "file" };

		OptWord opts_words;
		OptChars opts_chars;

		if (!opts_words.setArguments(argc, argv) ) {
			cout << "Could not set arguments. \n"
					<< "Leaving this world." << endl;
			throw(-1);
		}

		if (!opts_chars.setArguments(argc, argv) ) {
					cout << "Could not set arguments. \n"
							<< "Leaving this world." << endl;
					throw(-1);
				}

		opts_chars.setOptstring(validOpt);
		int args = opts_chars.numopt();
		if (args != 0) {
			cout << "Valid chars on cmdline: " << args << endl;
			for (int i = 1; i <= args; ++i) {
				string str = opts_chars.getopt();
				if (str != "INVALID")			//don't want to spam "INVALID"
						{
					cout << "Found match: -" << str << endl;

					if (str == "f") {
						case_file(argc, argv, i);
					}
				}
			}

		}

		//sets the valid options for '--' commands and count them up
		for (string n : validWords) {
			opts_words.setOptstring(n);
			args = opts_words.numopt();
			WordArgs += args;
		}
		if (WordArgs != 0) {
			cout << "valid words on cmdline: " << WordArgs << endl;

			//loop out the '--' commands. Nested for loop because words options
			// take a string each and needs to be set each time
			for (string n : validWords) {
				opts_words.setOptstring(n);

				for (int i = 1; i <= WordArgs; i++) {
					string str = opts_words.getopt();
					if (str != "INVALID")		//don't want to spam "INVALID"
							{
						cout << "Found match: --" << str << endl;

						if (str == "file") {
							case_file(argc, argv,i);
						}
						if (str =="log")
						{
							case_log(argc, argv, i);
						}



					}
				}
			}

		}
	} catch (int x) {
		cout << "ErrorID: " << x << endl;
	} catch (exception &s) {
		cout << "exception found: " << s.what() << endl;
	} catch (...) {
		cout << "something went wrong" << endl;
	}

	return 0;
}

void case_log(int argc, const char** argv, int i) {
	cout << "Ready to perform some logging action."<< endl;

	const char* filename = NULL;

	if (argc > i + 1) {
		filename = argv[i + 1];
		cout << "Here is the filename:\n " << filename << endl;
	} else
		cout << "No file name" << filename << endl;

	fileobj.setFileName(filename);
	fileobj.readFile();
}

void case_file(int argc, const char** argv, int i) {
	cout << "Ready to perform some file action."<< endl;

	const char* filename = NULL;
	if (argc > i +1)
	{
			filename = argv[i + 1];
			cout << "Here is the file/folder name:\n " << filename << endl;
	}else
				cout << "No file name" << filename << endl;

	//Dir_handler dir("/home/Tobias/workspace/exercise_13");
	Dir_handler dir(filename);
	dir.show_folder_content();

}
