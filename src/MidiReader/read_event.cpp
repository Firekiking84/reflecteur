// ************************************************
// 27/11/2024 16:58:43
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

char		*ef::MidiReader::read_event(char	*content,
					    t_event	&event)
{
  content += read_vlq(content, &event.delta_time);
  event.type = identify_event(content);
  if (event.type == UNKNOWN)
      return (NULL);
  content += 2;
  if (event.type < END_META)
    {
      content += read_vlq(content, &event.size);
      event.data = content;
      content += event.size;
    }
  else
    {
      if (event.type >= PROGRAM_CHANGE_CHN_1 && event.type <= PROGRAM_CHANGE_CHN_16)
	{
	  event.size = 1;
	  event.data = content;	  
	  content += event.size;
	}
      else if ((event.type >= NOTE_ON_CHN_1 && event.type <= NOTE_ON_CHN_16)
	       || (event.type >= NOTE_OFF_CHN_1 && event.type <= NOTE_OFF_CHN_16))
	{
	  event.note = *(uint8_t *)(content);
	  content += 1;
	  event.velocity = *(uint8_t *)(content);
	  content += 1;
	}
    }
  return (content);
}
