// ************************************************
// 15/11/2024 16:19:30
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

std::vector<ef::MidiReader::t_midi_file>::iterator	ef::MidiReader::remove(std::vector<t_midi_file>::iterator	file_it)
{
  for (auto it = file_it->data.begin(); it != file_it->data.end(); ++it)
    bunny_delete_sound(&((*it)->sound));
  return (loaded_files.erase(file_it));
}
