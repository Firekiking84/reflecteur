// ************************************************
// 07/11/2024 16:07:24
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"waveReader.hh"

int		ef::WaveReader::clear()
{
  for (auto it = loaded_files.begin(); it != loaded_files.end(); )
    it = remove(it);
  return (0);
}
