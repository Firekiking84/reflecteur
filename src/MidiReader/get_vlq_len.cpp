// ************************************************
// 21/11/2024 11:55:40
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		"midiReader.hh"

int			ef::MidiReader::get_vlq_len(const char	*data)
{
  int			i;

  i = 0;
  while (data[i] < 0)
    i += 1;
  return (i + 1);
}

int			ef::MidiReader::get_vlq_len(uint32_t	data)
{
  char			*str;
  int			len;
  int			i;

  str = (char *)&data;
  len = sizeof(data);
  i = len - 1;
  while (!str[i])
    {
      len -= 1;
      i -= 1;
    }
  return (len);
}
