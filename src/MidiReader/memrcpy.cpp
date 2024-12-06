// ************************************************
// 05/12/2024 03:01:31
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

void		*ef::MidiReader::memrcpy(void	*a,
					 void	*b,
					 int	len)
{
  char		*str_a;
  char		*str_b;
  int	        i;
 
  str_a = (char *)a;
  str_b = (char *)b;
  i = 0;
  while (i < len)
    {
      str_a[i] = str_b[len - 1 - i];
      i += 1;
    }
  return (a);
}
