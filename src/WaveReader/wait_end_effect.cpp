// ************************************************
// 07/11/2024 16:35:44
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"waveReader.hh"

void		ef::WaveReader::wait_end_effect(std::vector<t_bunny_effect *>	effects)
{
  bool		is_playing;

  is_playing = true;
  while (is_playing)
    {
      is_playing = false;
      for (auto it = effects.begin(); it != effects.end(); ++it)
	is_playing = is_playing || bunny_sound_is_playing(&((*it)->sound));
    }
}
