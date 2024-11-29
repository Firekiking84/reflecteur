// ************************************************
// 07/11/2024 15:40:37
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		"waveReader.hh"

int			ef::WaveReader::print_filelist()
{
  std::cout << "Loaded files : " << std::endl;
  for (auto it = loaded_files.begin(); it != loaded_files.end(); ++it)
    std::cout << "\t- " << it->filename << std::endl;
  return (0);
}
