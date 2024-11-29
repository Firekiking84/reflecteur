// ************************************************
// 15/11/2024 17:38:17
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

int		ef::MidiReader::clear()
{
  for (auto it = loaded_files.begin(); it != loaded_files.end(); )
    it = remove(it);
  return (0);
}
