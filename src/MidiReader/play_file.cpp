// ************************************************
// 15/11/2024 16:22:08
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		"midiReader.hh"

int			ef::MidiReader::play_file(std::string	filename)
{
  t_midi_file		*fileContent;

  fileContent = get_file(filename);
  if (!fileContent)
    return (-1);
  return (play(*fileContent, true));
}
