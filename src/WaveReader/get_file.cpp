// ************************************************
// 15/11/2024 11:14:01
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include			"waveReader.hh"

ef::WaveReader::t_wav_file		*ef::WaveReader::get_file(std::string	filename)
{
  for (auto it = loaded_files.begin(); it != loaded_files.end(); ++it)
    if (it->filename == filename)
      return (&(*it));
  std::cerr << "Didn't find the loaded file : " << filename << std::endl;
  return (NULL);
}
