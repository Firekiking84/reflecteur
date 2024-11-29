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
  int		i;
  int		len;

  for (i = 0; data[i] < 0; i += 1);
  len = i + 1;
  *out = 0;
  for (;i >= 0; i -= 1)
    {
      *out <<= 7; // On monte tout d'un octet
      *out += (data[i] & 0x7f); // On additionne que les 7 bits les moins importants
    }
  return (len);
}
