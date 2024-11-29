/* ************************************************ */
/* 31/10/2024 15:27:29 */
/* Keryan HOUSSIN  */
/* Reflecteur */
/* ************************************************ */

#include	"waveReader.hh"
#include	<fstream>

int		ef::WaveReader::read_header(std::ifstream	&file,
					    t_wav_file		&fileContent)
{
  file.read(reinterpret_cast<char *>(&fileContent.header), sizeof(fileContent.header));
  if (strncmp(fileContent.header.FileTypeBlocID, "RIFF", 4) != 0
      || strncmp(fileContent.header.FileFormatID, "WAVE", 4) != 0
      || strncmp(fileContent.header.FormatBlocID, "fmt ", 4) != 0
      || fileContent.header.AudioFormat != 1
      || fileContent.header.BlocSize == 0)
    {
      std::cerr << "File type not supported ! " << fileContent.filename << std::endl;
      return (-1);
    }
  while (strncmp(fileContent.header.data.DataBlocId, "data", 4) != 0)
    {
      file.seekg(fileContent.header.data.DataSize, std::ios::cur);
      if (!file.read(reinterpret_cast<char *>(&fileContent.header.data), sizeof(fileContent.header.data)))
	{
	  std::cerr << "Can't find data part of " << fileContent.filename << std::endl;
	  return (-1);
	}
    }
  return (0);
}
