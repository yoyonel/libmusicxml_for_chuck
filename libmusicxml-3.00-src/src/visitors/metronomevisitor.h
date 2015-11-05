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

#ifndef __metronomevisitor__
#define __metronomevisitor__

#include <vector>
#include <utility>
#include "typedefs.h"
#include "visitor.h"

namespace MusicXML2 
{

/*!
\addtogroup visitors
@{
*/

/*!
\brief key element data
*/
class EXP metronomevisitor : 
	public visitor<S_metronome>,
	public visitor<S_beat_unit>,
	public visitor<S_beat_unit_dot>,
	public visitor<S_per_minute>
{
	protected:
		typedef struct { std::string fUnit; int fDots; } beat;
		beat fCurrentBeat;

				void reset();
		virtual void reset(beat& b);
		virtual void visitStart( S_metronome& elt );
		virtual void visitEnd  ( S_metronome& elt );
		virtual void visitStart( S_beat_unit& elt );
		virtual void visitStart( S_beat_unit_dot& elt );
		virtual void visitStart( S_per_minute& elt );

	public:
				 metronomevisitor() { reset(); }
		virtual ~metronomevisitor() {}

		std::vector<beat> fBeats;
		int		fPerMinute;
};


/*! @} */

}

#endif
