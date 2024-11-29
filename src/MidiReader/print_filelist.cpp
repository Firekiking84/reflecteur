// ************************************************
// 15/11/2024 16:21:00
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		"midiReader.hh"

int			ef::MidiReader::print_filelist()
{
  std::cout << "Loaded files : " << std::endl;
  for (auto it = loaded_files.begin(); it != loaded_files.end(); ++it)
    std::cout << "\t- " << it->filename << std::endl;
  return (0);
}
