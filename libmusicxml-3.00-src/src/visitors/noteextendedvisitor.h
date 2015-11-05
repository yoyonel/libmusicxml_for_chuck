/*

  MusicXML Library
  Copyright (C) 2007  Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef NOTEEXTENDEDVISITOR_H
#define NOTEEXTENDEDVISITOR_H

#include <ostream>
#include <string>
#include "conversions.h"
#include "rational.h"
#include "typedefs.h"
#include "visitor.h"
#include "xml.h"

#include "notevisitor.h"

namespace MusicXML2
{

/*!
\addtogroup visitors
@{
*/

/*!
\brief A note visitor.
*/
class EXP noteextendedvisitor :
        public notevisitor,
        public visitor<S_fret>,
        public visitor<S_string>,
        public visitor<S_string_mute>
{

public:

    int        getFret() const { return fFret; }
    int        getString() const { return fString; }
    int        getString_mute() const { return fString_mute; }

protected:

    virtual void visitStart( S_fret& elt ) { fFret = int(*elt); }
    virtual void visitStart( S_string& elt ) { fString = int(*elt); }
    virtual void visitStart( S_string_mute& elt ) { fString_mute = int(*elt); }

private:

    int        fFret;
    int        fString;
    int        fString_mute;

};

EXP std::ostream& operator<< (std::ostream& os, const noteextendedvisitor& elt);

/*! @} */

}

#endif // NOTEEXTENDEDVISITOR_H
