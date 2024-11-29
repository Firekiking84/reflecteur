// ************************************************
// 07/11/2024 14:52:40
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		"waveReader.hh"

int			ef::WaveReader::play_file(std::string	filename)
{
  t_wav_file		*fileContent;

  fileContent = get_file(filename);
  if (!fileContent)
    return (-1);
  return (play(*fileContent, true));
}
