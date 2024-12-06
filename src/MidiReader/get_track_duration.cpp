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
  bool		valid_duration;
  int		timeMod;

  duration = 0;
  tempo = 500000;
  valid_duration = false;
  fileContent.time.n_mod = 0;
  timeMod = 1;
  fileContent.time.mod_delta_time = 0;
  delta_time = 0;
  for (i = 0; i < events.size(); i += 1)
    {
      fileContent.time.mod_delta_time += events[i].delta_time;
      delta_time += events[i].delta_time;
      if (fileContent.time.time_mods.size() > fileContent.time.n_mod &&
	  fileContent.time.time_mods[fileContent.time.n_mod].delta_time < fileContent.time.mod_delta_time)
	{
	  duration += delta_time * ((double)tempo / (fileContent.header.timeDivision * timeMod) / 1000000);
	  delta_time = 0;
	  fileContent.time.mod_delta_time = 0;
	  timeMod = fileContent.time.time_mods[fileContent.time.n_mod].tickPerDiv;
	  fileContent.time.n_mod += 1;
	}
      if (events[i].type == SET_TEMPO)
	{
	  t_converter	converter;

	  duration += delta_time * ((double)tempo / (fileContent.header.timeDivision * timeMod) / 1000000);
	  delta_time = 0;
	  converter.bytes[3] = 0;
	  memrcpy(converter.bytes, events[i].data, 3);
	  tempo = converter.value;
	}
      else if (events[i].type == TIME_SIGNATURE)
	{
	  t_time_mod	mod;
	  char		tmp[4];

	  mod.delta_time = events[i].delta_time;
	  memcpy(tmp, events[i].data, 4);
	  mod.tickPerDiv = (int)tmp[2];
	  fileContent.time.time_mods.push_back(mod);
	}
      else if (events[i].type >= NOTE_ON_CHN_1 && events[i].type <= NOTE_ON_CHN_16)
	valid_duration = true;
    }
  if (valid_duration)
    duration += delta_time * ((double)tempo / (fileContent.header.timeDivision * timeMod) / 1000000);
  else
    duration = 0;
  return (duration);
}
