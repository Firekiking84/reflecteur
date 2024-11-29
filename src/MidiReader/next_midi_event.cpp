// ************************************************
// 22/11/2024 11:01:35
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

void		*ef::MidiReader::next_midi_event(void	*track)
{
  char		*str;
  char		mask;

  mask = ~0;
  str = (char *)track;
  while (~(*str & mask))
    str++;
  return ((void *)str);
}
