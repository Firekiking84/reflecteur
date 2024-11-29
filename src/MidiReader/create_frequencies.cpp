// ************************************************
// 29/11/2024 01:59:21
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

void		ef::MidiReader::create_sound(t_sound	&sound)
{
  int		i;
  double	ratio;
  int		i_sample;
  int		len_sample;

  len_sample = SAMPLE_PER_SECONDS * (1.0 / sound.frequency);
  i_sample = 0;
  i = sound.start;
  while (i < sound.stop)
    {
      ratio = get_ratio(0, len_sample, i_sample);
      sound.effect->sample[i] = cos(ratio * 2.0 * M_PI) * 10000;
      i += 1;
      i_sample += 1;
      if (i_sample == len_sample)
	i_sample = 0;
    }
}
 
