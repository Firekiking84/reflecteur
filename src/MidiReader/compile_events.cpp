// ************************************************
// 29/11/2024 01:55:26
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		<map>
#include		<cstring>

#include		"midiReader.hh"

int			ef::MidiReader::compile_events(t_midi_file		&fileContent,
						       std::vector<t_event>	&events)
{
  t_bunny_effect	*effect;
  t_sound		sound;
  std::map<int, t_sound>	sounds_in_progress;
  size_t		i;
  uint32_t		n_sample;
  uint32_t		delta_time;
  uint32_t		tempo;
  t_converter		converter;
  int			timeMod;

  effect = create_new_effect(fileContent.time.duration);
  n_sample = 0;
  tempo = 500000;
  delta_time = 0;
  timeMod = 1;
  fileContent.time.n_mod = 0;
  fileContent.time.mod_delta_time = 0;
  for (i = 0; i < events.size(); i += 1)
    {
      delta_time += events[i].delta_time;
      refresh_position(n_sample, tempo, delta_time, fileContent, timeMod);
      if (events[i].type >= NOTE_ON_CHN_1 && events[i].type <= NOTE_ON_CHN_16)
	{
	  auto it = sounds_in_progress.find((events[i].type - NOTE_ON_CHN_1) * 1000 + events[i].note);

	  if (it == sounds_in_progress.end())
	    {
	      sound.start = n_sample;
	      sound.velocity = events[i].velocity;
	      sound.frequency = piano[events[i].note];
	      sound.effect = effect;
	      sounds_in_progress[(events[i].type - NOTE_ON_CHN_1) * 1000 + events[i].note] = sound;
	    }
	}
      else if (events[i].type >= NOTE_OFF_CHN_1 && events[i].type <= NOTE_OFF_CHN_16)
	{
	  auto it = sounds_in_progress.find((events[i].type - NOTE_OFF_CHN_1) * 1000 + events[i].note);

	  if (it != sounds_in_progress.end())
	    {
	      sound = it->second;
	      sound.stop = n_sample;
	      create_sound(sound);
	      sounds_in_progress.erase(it);
	    }
	}
      else if (events[i].type == SET_TEMPO)
	{
	  converter.bytes[3] = 0;
	  memrcpy(converter.bytes, events[i].data, 3);
	  tempo = converter.value;
	  std::cout << "Tempo : " << tempo << std::endl;
	}
    }
  fileContent.data.push_back(effect);
  return (0);
}
