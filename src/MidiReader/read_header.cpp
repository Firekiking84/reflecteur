// ************************************************
// 15/11/2024 16:49:30
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

#include	<arpa/inet.h>

int		ef::MidiReader::read_header(std::ifstream	&file,
					    t_midi_file		&fileContent)
{
  file.read(reinterpret_cast<char *>(&fileContent.header), sizeof(fileContent.header));
  fileContent.header.size = ntohl(fileContent.header.size);
  fileContent.header.format = ntohs(fileContent.header.format);
  fileContent.header.nbTracks = ntohs(fileContent.header.nbTracks);
  fileContent.header.timeDivision = ntohs(fileContent.header.timeDivision);
  if (strncmp(fileContent.header.id, "MThd", 4) != 0
      || fileContent.header.format > 1)
    {
      std::cerr << "File not supported : " << fileContent.filename << std::endl;
      return (-1);
    }
  uint16_t	mask;

  mask = 1 << 15;
  if (fileContent.header.timeDivision & mask)
    {
      std::cerr << "Division format not supported : " << fileContent.filename << std::endl;
      return (-1);
    }
  return (0);
}
