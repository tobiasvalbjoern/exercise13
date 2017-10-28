#ifndef OPTCHARS_H
#define OPTCHARS_H
#include "Options.h"

/*derived from class Options
 * It can handle options like "-a"*/
class OptChars : public Options
{
public:
    OptChars();
    virtual ~OptChars(){};

    //returns the first occurrence of a valid -"CHAR" on cmd
    string getopt(void);
};

#endif // OPTCHARS_H
