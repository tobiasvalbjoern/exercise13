//============================================================================
// Name        : Exercise 13
// Author      : Tobias Valbjørn
// Date		   : 27/10/2017
// Copyright   : No copyright.
// Description : This is a solution for class exercise 13. See exercise on pdf
//				 for further explanation and README. Error numbers can be found
//				 in the README.
//				 The Dir_handler functionality is made in cooperation with
//				 with Anders Reiche.
//============================================================================
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <vector>

#include "Opt_word.h"
#include "Options.h"
#include "Dir_handler.h"
#include "Log.h"
#include "Opt_chars.h"

using namespace std;

int main(int argc, const char ** argv) {
	try {

		OptWord opts_words;
		OptChars opts_chars;

		if (!opts_words.setArguments(argc, argv)) {
			cout << "Could not set arguments. \n"<< endl;
			throw(-1);
		}

		if (!opts_chars.setArguments(argc, argv)) {
			cout << "Could not set arguments. \n" <<endl;
			throw(-1);
		}

		string validChars = "abod";
		opts_chars.setOptstring(validChars);

		int args = opts_chars.numopt();

		/*If no valid options are returned, we can skip this block*/
		if (args != 0) {
			cout << "Valid chars on cmdline: " << args << endl;
			for (int i = 1; i <= args; ++i) {
				string str = opts_chars.getopt();
				/*Invalid is returned when no opts where found*/
				if (str != "INVALID") {
					cout << "Found match: -" << str << endl;

					if (str == "d") {
						string path = opts_chars.get_path();
						Dir_handler dir(path);
						dir.show_folder_content();
					}
				}
			}

		} else {
			cout << "No '-' match found" << endl;
		}

		vector<string> validWords { "log", "help", "dir" };
		args = 0;

		for (auto n : validWords) {
			opts_words.setOptstring(n);
			args += opts_words.numopt();

		}
		if (args != 0) {
			cout << "valid words on cmdline: " << args << endl;

			//loop out the '--' commands. Nested for loop because words options
			// take a string each and needs to be set each time
			for (string n : validWords) {
				opts_words.setOptstring(n);

				for (int i = 1; i <= args; i++) {
					string str = opts_words.getopt();
					if (str != "INVALID") {
						cout << "Found match: --" << str << endl;

						if (str == "dir") {
							string path = opts_words.get_path();
							Dir_handler dir(path);
							dir.show_folder_content();

						}
						if (str == "log") {
							string path = opts_words.get_path();
							Log log;
							log.log(path);
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
