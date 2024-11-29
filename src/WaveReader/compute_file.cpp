// ************************************************
// 07/11/2024 15:13:17
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"waveReader.hh"

int		ef::WaveReader::compute_file(t_wav_file	&fileContent)
{
  bool		error;

  error = false;
  for (auto it = fileContent.data.begin(); it != fileContent.data.end(); ++it)
    error = error || !bunny_compute_effect(*it);
  if (error)
    {
      std::cerr << "We encountered an error during computing effect of " << fileContent.filename << std::endl;
      return (-1);
    }
  return (0);
}

