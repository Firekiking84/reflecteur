// ************************************************
// 15/11/2024 17:40:57
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	<filesystem>

#include	"midiReader.hh"

namespace fs = std::filesystem;

void		ef::MidiReader::load_dir(std::string	dirName)
{
  std::vector<std::string>	filenames;

  for (const auto &entry : fs::directory_iterator(dirName))
    filenames.push_back(entry.path());
  load_files(filenames);
}
