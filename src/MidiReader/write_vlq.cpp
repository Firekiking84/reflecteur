// ************************************************
// 21/11/2024 12:00:54
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

int		ef::MidiReader::write_vlq(uint32_t	data,
					  char		*out)
{
  char		*str_data;
  int		i;
  int		len;
  int		cbegin;
  char		bin_mask;

  str_data = (char *)&data;
  bin_mask = 1 << 7;
  len = get_vlq_len(data);
  cbegin = len - 1;
  i = 0;
  while (i < len)
    {
      if ((i + 1) < len)
	str_data[cbegin - i] |= bin_mask;
      out[i] = str_data[cbegin - i];
      i += 1;
    }
  return (len);
}
