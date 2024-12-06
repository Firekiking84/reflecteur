// ************************************************
// 29/11/2024 02:59:37
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

void		ef::MidiReader::refresh_position(uint32_t	&n_sample,
						 uint32_t	&tempo,
						 uint32_t	&delta_time,
						 t_midi_file	&fileContent,
						 int		&timeMod)
{
  uint32_t	sample_ellapsed;

  fileContent.time.mod_delta_time += delta_time;
  sample_ellapsed = delta_time * ((double)tempo / (fileContent.header.timeDivision * timeMod));
  sample_ellapsed = (double)sample_ellapsed / 1000000 * SAMPLE_PER_SECONDS;
  n_sample += sample_ellapsed;
  if (fileContent.time.time_mods.size() > fileContent.time.n_mod &&
      fileContent.time.time_mods[fileContent.time.n_mod].delta_time < fileContent.time.mod_delta_time)
    {
      fileContent.time.mod_delta_time = 0;
      timeMod = fileContent.time.time_mods[fileContent.time.n_mod].tickPerDiv;
      fileContent.time.n_mod += 1;
    }
  delta_time = 0;  
}
