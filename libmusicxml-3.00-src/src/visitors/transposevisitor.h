/*

  MusicXML Library
  Copyright (C) 2006,2007  Grame

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

#ifndef __transposeVisitor__
#define __transposeVisitor__

#include "typedefs.h"
#include "visitor.h"

namespace MusicXML2 
{

/*!
\addtogroup visitors
@{
*/

/*!
\brief a musicxml transpose element visitor
*/
class EXP transposevisitor : 
	public visitor<S_transpose>,
	public visitor<S_diatonic>,
	public visitor<S_chromatic>,
	public visitor<S_octave_change>,
	public visitor<S_double>
{
	protected:
		virtual void visitStart( S_transpose& elt );
		virtual void visitStart( S_diatonic& elt );
		virtual void visitStart( S_chromatic& elt );
		virtual void visitStart( S_octave_change& elt );
		virtual void visitStart( S_double& elt );

	public:
				 transposevisitor() { reset(); }
		virtual ~transposevisitor() {}
		virtual void reset();

		int		fDiatonic;
		int		fChromatic;
		int		fOctaveChange;
		bool	fDouble;
};


/*! @} */

}

#endif
