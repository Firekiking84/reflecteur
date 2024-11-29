// ************************************************
// 27/11/2024 17:49:17
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

ef::MidiReader::t_event_type	ef::MidiReader::identify_event(char	*data)
{
  if (*data != -1)
    {
      uint8_t	type;
      uint8_t	channel;
      uint8_t	byte;

      byte = *((uint8_t *)data);
      type = byte >> 4;
      channel = byte << 4;
      channel = channel >> 4;
      if (type == 12)
	return ((t_event_type)(PROGRAM_CHANGE_CHN_1 + channel));
      if (type == 9)
	return ((t_event_type)(NOTE_ON_CHN_1 + channel));
      if (type == 8)
	return ((t_event_type)(NOTE_OFF_CHN_1 + channel));
      return (UNKNOWN);
    }
  data += 1;
  if (*data <= 7)
    return ((t_event_type)(SEQUENCE + *data));
  if (*data == 32)
    return (MIDI_CHANNEL_PREFIX);
  if (*data == 47)
    return (END);
  if (*data == 81)
    return (SET_TEMPO);
  if (*data == 84)
    return (SMPTE_OFFSET);
  if (*data == 88)
    return (TIME_SIGNATURE);
  if (*data == 89)
    return (KEY_SIGNATURE);
  if (*data == 127)
    return (SEQUENCER_SPECIFIC);
  return (UNKNOWN);
}
