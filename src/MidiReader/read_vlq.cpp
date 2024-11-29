// ************************************************
// 21/11/2024 11:43:42
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"
#include	<cstring>

int		ef::MidiReader::read_vlq(const char	*data,
					 uint32_t	*out)
{
  int		len;
  int		cbegin;
  int		i;
  char		*str_out;
  char		data_cpy[4];

  memcpy(data_cpy, data, 4);
  len = get_vlq_len(data_cpy);
  cbegin = len - 1;
  *out = 0;
  str_out = (char *)out;
  i = 0;
  while (i < len)
    {
      data_cpy[cbegin - i] = data_cpy[cbegin - i] << 1;
      data_cpy[cbegin - i] = data_cpy[cbegin - i] >> 1;
      str_out[i] = data_cpy[cbegin - i];
      i += 1;
    }
  return (len);
}
