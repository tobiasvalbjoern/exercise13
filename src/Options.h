#ifndef OPTIONS_H_
#define OPTIONS_H_
#include <string>
#include <vector>

using namespace std;

/*Abstract parent class for opt_word and opt_char.*/
class Options
{
public:
    Options();
    virtual ~Options(){};
    bool setArguments (int argc,const char **argv);

    void setOptstring(string &validopt);

	//abstract method. It is implemented in Opt_char and Opt_word.
    virtual string getopt(void) = 0;

    /*Returns number of validoptions found.*/
    int numopt(void);

    /*This function can be used to get a path on the cmd line that is given
     * after a valid option, like -f /home/documents/, depending on the path */
	string get_path();

protected: 
	int argC;
	vector<string> argV{};

	//get_opt uses this counter to remember the position it reached
	//on commandline before returning the string.
	int count;

	//a container for the valid option(s)
	string optstring;

};

#endif /* OPTIONS_H_ */
