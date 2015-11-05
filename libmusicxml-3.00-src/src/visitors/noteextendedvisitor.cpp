#include <iostream>
#include "noteextendedvisitor.h"

//#define PRINTNOTE

using namespace std;

namespace MusicXML2 {

//________________________________________________________________________
ostream& operator<< (ostream& os, const noteextendedvisitor & elt)
{
    elt.print(os);
    return os;
}

}
