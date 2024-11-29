// ************************************************
// 31/10/2024 13:04:29
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		<fstream>
#include		<cstring>

#include		"waveReader.hh"

int			ef::WaveReader::load_file(std::string	&filename)
{
  std::ifstream		file(filename, std::ios::binary);

  if (!file || !file.is_open())
    {
      std::cerr << "Can't open file : " << filename << std::endl;
      return(-1);
    }
  t_wav_file		fileContent;

  fileContent.filename = filename;
  if (read_header(file, fileContent) == -1)
    {
      file.close();
      std::cerr << "Failed while reading header" << std::endl;
      return (-1);
    }
  fileContent.info.duration = fileContent.header.data.DataSize / fileContent.header.BytePerSec;
  fileContent.info.BytePerSample = fileContent.header.BitsPerSample / 8;
  fileContent.info.samplePerSec = fileContent.header.BytePerSec / fileContent.info.BytePerSample;
  fileContent.info.nbSample = fileContent.info.samplePerSec * fileContent.info.duration;
  set_sounds(fileContent);
  if (read_content(file, fileContent) == -1)
    {
      file.close();
      std::cerr << "Failed while reading content" << std::endl;
      return (-1);
    }
  file.close();
  loaded_files.push_back(fileContent);
  return (0);
}
