#ifndef OPTWORD_H
#define OPTWORD_H
#include "Options.h"

/*derived from class Options
 * It can handle options like "--log"*/
class OptWord : public Options
{
public:
    OptWord();
    virtual ~OptWord(){};

    //returns the first occurrence of a valid --"WORD" on cmd
	string getopt(void);
};

#endif // OPTWORD_H
