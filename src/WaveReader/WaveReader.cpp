// ************************************************
// 31/10/2024 11:54:56
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		"waveReader.hh"

ef::WaveReader::WaveReader(std::vector<std::string>	filenames)
{
  load_files(filenames);
}

ef::WaveReader::WaveReader(std::string			filename)
{
  std::vector<std::string>	filenames;

  filenames.push_back(filename);
  load_files(filenames);
}

ef::WaveReader::WaveReader()
{
}

ef::WaveReader::~WaveReader()
{
  clear();
}
