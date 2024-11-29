// ************************************************
// 07/11/2024 15:35:51
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"waveReader.hh"

int		ef::WaveReader::play_all()
{
  for (auto it = loaded_files.begin(); it != loaded_files.end(); ++it)
    {
      if (play(*it, true) == -1)
	return (-1);
    }
  return (0);
}
