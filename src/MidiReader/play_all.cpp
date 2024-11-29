// ************************************************
// 15/11/2024 16:24:39
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

int		ef::MidiReader::play_all()
{
  for (auto it = loaded_files.begin(); it != loaded_files.end(); ++it)
    {
      if (play(*it, true) == -1)
	return (-1);
    }
  return (0);
}
