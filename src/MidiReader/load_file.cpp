// ************************************************
// 15/11/2024 16:30:04
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

int		ef::MidiReader::load_file(std::string	&filename)
{
  std::ifstream	file(filename, std::ios::binary);

  if (!file || !file.is_open())
    {
      std::cerr << "Can't open file :" << filename << std::endl;
      return (-1);
    }
  t_midi_file	fileContent;

  fileContent.filename = filename;
  if (read_header(file, fileContent) == -1)
    {
      file.close();
      std::cerr << "Failed while reading header in " << filename << std::endl;
      return (-1);
    }
  if (read_content(file, fileContent) == -1)
    {
      file.close();
      std::cerr << "Failed while reading content in " << filename << std::endl;
      return (-1);
    }
  loaded_files.push_back(fileContent);
  return (0);
}
