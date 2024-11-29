// ************************************************
// 07/11/2024 15:57:07
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include					"waveReader.hh"

std::vector<ef::WaveReader::t_wav_file>::iterator	ef::WaveReader::remove(std::vector<t_wav_file>::iterator	file_it)
{
  for (auto it = file_it->data.begin(); it != file_it->data.end(); ++it)
    bunny_delete_sound(&((*it)->sound));
  return (loaded_files.erase(file_it));
}
