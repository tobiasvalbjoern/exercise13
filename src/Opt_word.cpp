#include "Opt_word.h"

#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;

OptWord::OptWord() {
}

//This looks for the WORD commands starting with '--'
string OptWord::getopt(void) {

	for (; count < argC-1; count++) {

		if (argV[count][0] == '-' && argV[count][1] == '-'
				&& argV[count].size() > 3) {
			string str(argV[count]);

			//We don't want to return a word with double dashes.
			str.erase(str.begin(),str.begin()+2);

			if (str == optstring) {
				count++;
				return (optstring);
			}
		}
	}
	//If no opts are found and we have moved through all arguments on cmd
	//return "INVALID"
	return ("INVALID");
}
