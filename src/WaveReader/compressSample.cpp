// ************************************************
// 14/11/2024 15:59:52
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"waveReader.hh"

int		ef::WaveReader::compressSample(int64_t	sample,
					       uint16_t	nbBits)
{
  return (sample >> (nbBits - 16));
}
