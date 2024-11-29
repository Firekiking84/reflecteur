// ************************************************
// 07/11/2024 15:04:02
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"waveReader.hh"

int		ef::WaveReader::play(t_wav_file		&fileContent,
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
