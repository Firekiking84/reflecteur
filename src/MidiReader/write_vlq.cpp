// ************************************************
// 21/11/2024 12:00:54
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

int		ef::MidiReader::write_vlq(uint32_t	data,
					  char		*out)
{
  int		i;

  i = 0;
  while (data >= 128)
    {
      out[i] = (data & 0x7F) | 0x80;
      data >>= 7;
      i += 1;
    }
  out[i] = data;
  return (i + 1);
}
