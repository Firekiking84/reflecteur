// ************************************************
// 15/11/2024 16:27:33
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"
#include	<filesystem>

namespace fs = std::filesystem;

void		ef::MidiReader::load_files(std::vector<std::string>	&filenames)
{
  size_t	i;

  for (i = 0; i < filenames.size(); i += 1)
    {
      if (fs::exists(filenames[i]))
	{
	  if (fs::is_regular_file(filenames[i]))
	    load_file(filenames[i]);
	  else if (fs::is_directory(filenames[i]))
	    load_dir(filenames[i]);
	  else
	    std::cerr << "Cannot load : " << filenames[i] << std::endl;
	}
      else
	std::cerr << "Cannot find file : " << filenames[i] << std::endl;
    }
}
