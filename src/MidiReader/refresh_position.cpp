// ************************************************
// 29/11/2024 02:59:37
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

void		ef::MidiReader::refresh_position(uint32_t	&n_sample,
						 uint32_t	&tempo,
						 uint32_t	&delta_time,
						 t_midi_file	&fileContent)
{
  uint32_t	sample_ellapsed;

  sample_ellapsed = delta_time * ((double)tempo / fileContent.header.timeDivision);
  sample_ellapsed = sample_ellapsed / 1000000 * SAMPLE_PER_SECONDS;
  n_sample += sample_ellapsed;
  delta_time = 0;  
}
