/* ************************************************ */
/* 31/10/2024 15:35:39 */
/* Keryan HOUSSIN  */
/* Reflecteur */
/* ************************************************ */

#include	<fstream>
#include	"waveReader.hh"

int		ef::WaveReader::read_content(std::ifstream	&file,
					     t_wav_file		&fileContent)
{
  size_t	i;
  size_t	nBlock;
  int64_t	sample;

  nBlock = 0;
  for (i = 0; i < fileContent.info.nbSample; i += 1)
    {
      fileContent.data[i % fileContent.header.NbrCanaux]->sample[nBlock] = 0;
      sample = 0;
      file.read(reinterpret_cast<char *>(&sample), fileContent.info.BytePerSample);
      if (fileContent.header.BitsPerSample > 16)
	sample = compressSample(sample, fileContent.header.BitsPerSample);
      fileContent.data[i % fileContent.header.NbrCanaux]->sample[nBlock] = static_cast<int16_t>(*reinterpret_cast<int64_t*>(&sample));
      if (i != 0 && (i % fileContent.header.NbrCanaux) == 0)
	nBlock += 1;
    }
  return (0);
}
