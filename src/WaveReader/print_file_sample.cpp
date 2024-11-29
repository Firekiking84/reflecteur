// ************************************************
// 15/11/2024 11:09:10
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		"waveReader.hh"

void			ef::WaveReader::print_file_sample(std::string		filename)
{
  t_wav_file		*fileContent;
  size_t		i;
  int			nChannel;

  fileContent = get_file(filename);
  if (!fileContent)
    return ;
  for (i = 0; i < fileContent->info.nbSample; i += 1)
    {
      for (nChannel = 0; nChannel < fileContent->header.NbrCanaux; nChannel += 1)
	std::cout << fileContent->data[nChannel]->sample[i] << ";";
      std::cout << std::endl;
    }
}
