// ************************************************
// 15/11/2024 16:26:02
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

int		ef::MidiReader::play(t_midi_file	&fileContent,
				     bool		wait_end)
{
  if (compute_file(fileContent) == -1)
    return (-1);
  for (auto it = fileContent.data.begin(); it != fileContent.data.end(); ++it)
    bunny_sound_play(&((*it)->sound));
  if (wait_end)
    wait_end_effect(fileContent.data);
  return(0);
}