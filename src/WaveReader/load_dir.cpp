// ************************************************
// 14/11/2024 12:08:34
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	<filesystem>
#include	"waveReader.hh"

namespace fs = std::filesystem;

void		ef::WaveReader::load_dir(std::string		dirName)
{
  std::vector<std::string>	filenames;
  
  for (const auto& entry: fs::directory_iterator(dirName))
    filenames.push_back(entry.path());
  load_files(filenames);
}
