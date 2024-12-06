// ************************************************
// 05/12/2024 01:42:05
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		"midiReader.hh"

t_bunny_effect		*ef::MidiReader::create_new_effect(double	duration)
{
  t_bunny_effect	*effect;
  size_t		nb_sample;
  size_t		i;

  if (duration < 1)
    effect = bunny_new_effect(duration + 1);
  else
    effect = bunny_new_effect(duration);
  nb_sample = SAMPLE_PER_SECONDS * duration;
  for (i = 0; i < nb_sample; i += 1)
    effect->sample[i] = 0;
  return (effect);
}
