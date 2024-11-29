// ************************************************
// 15/11/2024 17:25:40
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		"midiReader.hh"

ef::MidiReader::t_midi_file	*ef::MidiReader::get_file(std::string	filename)
{
  for (auto it = loaded_files.begin(); it != loaded_files.end(); ++it)
    if (it->filename == filename)
      return (&(*it));
  std::cerr << "Didn't find the loaded file : " << filename << std::endl;
  return (NULL);
}
