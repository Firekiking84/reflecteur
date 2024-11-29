// ************************************************
// 27/11/2024 11:17:28
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

int		ef::MidiReader::read_content(std::ifstream	&file,
					     t_midi_file	&fileContent)
{
  uint32_t	size_read;

  size_read = 0;
  while (size_read < fileContent.header.size)
    read_track(file, fileContent, size_read);
  return (0);
}
