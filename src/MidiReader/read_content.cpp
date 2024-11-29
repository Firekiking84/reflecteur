// ************************************************
// 27/11/2024 11:17:28
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

int		ef::MidiReader::read_content(std::ifstream	&file,
					     t_midi_file	&fileContent)
{
  uint32_t	n_channel;

  for (n_channel = 0; n_channel < fileContent.header.nbTracks; n_channel += 1)
    read_track(file, fileContent);
  return (0);
}
