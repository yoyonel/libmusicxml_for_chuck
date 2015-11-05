/*

  MusicXML Library
  Copyright (C) 2003-2006  Grame

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

#ifndef __versions__
#define __versions__

#include "exports.h"

namespace MusicXML2 
{

/*!
\addtogroup MusicXML
@{
*/


/*!
\brief Library and components version information.
*/
//______________________________________________________________________________
class EXP versions {
    public:
		static int			libVersion();
		static const char*	libVersionStr();

		static int			xml2guidoVersion();
		static const char*	xml2guidoVersionStr();

};

}

#endif
