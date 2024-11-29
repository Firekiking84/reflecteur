// ************************************************
// 29/11/2024 02:02:59
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

double		ef::MidiReader::get_ratio(int       a,
					  int       b,
					  int       x)
{
  return ((double)(x - a) / (b - a));
}
