#include "Opt_chars.h"

#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>

using namespace std;

OptChars::OptChars()
{
}

//This looks for the first occurrence of a match on a valid opt
//starting with '-' and a char.
string OptChars::getopt(void)
{
	for (; count < (argC-1); count++)
	{

		//char commands can be stored in a single string, so we loop it by char
		for (size_t j = 0; j < optstring.size(); j++)
		{

			//first element should be '-' and ALWAYS 2 elements long like "-a"
			if (argV[count][0] == '-' && argV[count].size() == 2)
			{
			if(argV[count][1] == optstring[j])
					{
				count++;
				return (optstring.substr(j,1));
					}
				}
			}
		}

	return ("INVALID");							//If no, return "INVALID"
}
