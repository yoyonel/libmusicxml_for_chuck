/*

  Copyright (C) 2003-2008  Grame
  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

  This file is provided as an example of the MusicXML Library use.
*/

#ifdef WIN32
#pragma warning(disable : 4786)
#endif

#include <string.h>
#include <iostream>
#include <sstream>

#include "xml.h"
#include "xmlfile.h"
#include "xmlreader.h"
#include "midicontextvisitor.h"
#include "unrolled_xml_tree_browser.h"

using namespace std;
using namespace MusicXML2;

// url: http://stackoverflow.com/questions/1430757/c-vector-to-string
template <class Str, class It>
Str join(It begin, const It end, const Str &sep) {
  typedef typename Str::value_type char_type;
  typedef typename Str::traits_type traits_type;
  typedef typename Str::allocator_type allocator_type;
  // url: http://www.cplusplus.com/reference/sstream/ostringstream/
  typedef std::basic_ostringstream<char_type, traits_type, allocator_type>
      ostringstream_type;
  ostringstream_type result;

  if (begin != end) result << *begin++;
  while (begin != end) {
    result << sep;
    result << *begin++;
  }
  return result.str();
}

// url:
// http://stackoverflow.com/questions/19094340/stdvector-as-a-template-function-argument
template <typename T, typename A>
void cout_vector(std::vector<T, A> const &vec,
                 const std::string &id_name = "",
                 const std::string &separator = ",") {
  cout << "- array of " << id_name << " -" << std::endl
       << "[" << join(vec.begin(), vec.end(), separator) << std::endl
       << "]" << std::endl;
}

//_______________________________________________________________________________
class mychuckwriter : public midiwriter {
 public:
  mychuckwriter() {}

  virtual ~mychuckwriter() {}

  virtual void startPart(int instrCount) {
    cout << "startPart with " << instrCount << " instrument(s)" << endl;
  }

  virtual void newInstrument(std::string instrName, int chan = -1) {
    cout << "newInstrument \"" << instrName << "\" on chan " << chan << endl;
  }

  virtual void endPart(long date) {
    cout << date << " endPart" << endl;

    cout << "Nb notes: " << this->m_vec_date.size() << endl;

    cout_vector(this->m_vec_date, "dates");
    cout_vector(this->m_vec_pitch, "id midi note");
    cout_vector(this->m_vec_dur, "durations");
    cout_vector(this->m_vec_fret, "frets");
    cout_vector(this->m_vec_string, "strings");
  }

  virtual void newNote(long date, int chan, float pitch, int vel, int dur,
                       int fret, int string, int string_mute) {
    // cout << date << " newNote [" << chan << "," << pitch << "," << vel << ","
    // << dur << "," << fret << "," << string <<
    //"," << string_mute << "]" << endl;
    this->m_vec_date.push_back(date);
    this->m_vec_pitch.push_back(int(pitch));
    this->m_vec_dur.push_back(dur);
    this->m_vec_fret.push_back(fret);
    this->m_vec_string.push_back(string);
  }

  virtual void newNote(long date, int chan, float pitch, int vel, int dur) {
    cout << date << " newNote [" << chan << "," << pitch << "," << vel << ","
         << dur << "]" << endl;
  }

  virtual void tempoChange(long date, int bpm) {
    cout << date << " tempoChange " << bpm << endl;
  }

  virtual void pedalChange(long date, pedalType t, int value) {
    cout << date << " pedalChange type " << t << " val " << value << endl;
  }

  virtual void volChange(long date, int chan, int vol) {
    cout << date << " volChange chan  " << chan << " vol " << vol << endl;
  }

  virtual void bankChange(long date, int chan, int bank) {
    cout << date << " bankChange chan " << chan << " bank " << bank << endl;
  }

  virtual void progChange(long date, int chan, int prog) {
    cout << date << " progChange chan " << chan << " prog " << prog << endl;
  }

 protected:
  std::vector<long> m_vec_date;
  std::vector<int> m_vec_pitch;
  std::vector<int> m_vec_dur;
  std::vector<int> m_vec_fret;
  std::vector<int> m_vec_string;
};

//_______________________________________________________________________________
int main(int argc, char *argv[]) {
  char *file = argv[1];
  xmlreader r;
  SXMLFile xmlfile;
  if ((argc > 1) && strcmp(file, "-"))
    xmlfile = r.read(file);
  else
    xmlfile = r.read(stdin);
  if (xmlfile) {
    Sxmlelement st = xmlfile->elements();
    if (st) {
      mychuckwriter writer;
      midicontextvisitor v(480, &writer);
      unrolled_xml_tree_browser browser(&v);
      browser.browse(*st);
    }
  }
  return 0;
}
