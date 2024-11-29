// ************************************************
// 07/11/2024 15:52:13
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		"waveReader.hh"

int			ef::WaveReader::remove_file(std::string	filename)
{
  for (auto it = loaded_files.begin(); it != loaded_files.end(); ++it)
    {
      if (it->filename == filename)
	{
	  remove(it);
	  return (0);
	}
    }
  std::cerr << "Didn't find the loaded file to remove : " << filename << std::endl;
  return (-1);
}
