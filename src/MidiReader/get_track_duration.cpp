// ************************************************
// 28/11/2024 10:23:28
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

#include	<cmath>
#include	<cstring>

double		ef::MidiReader::get_track_duration(std::vector<t_event>	&events,
						   t_midi_file		&fileContent)
{
  size_t	i;
  double	duration;
  uint32_t	delta_time;
  uint32_t	tempo;

  duration = 0;
  tempo = 500000;
  delta_time = 0;
  for (i = 0; i < events.size(); i += 1)
    {
      delta_time += events[i].delta_time;
      if (events[i].type == SET_TEMPO)
	{
	  duration += delta_time * ((double)tempo / fileContent.header.timeDivision) / 1000000;
	  delta_time = 0;
	  tempo = 0;
	  memcpy(&tempo, events[i].data, 3);
	}
    }
  duration += delta_time * ((double)tempo / fileContent.header.timeDivision) / 1000000;
  return (duration);
}
