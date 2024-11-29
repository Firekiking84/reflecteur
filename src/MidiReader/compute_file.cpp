// ************************************************
// 15/11/2024 17:13:21
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"midiReader.hh"

int		ef::MidiReader::compute_file(t_midi_file	&fileContent)
{
  bool		error;

  error = false;
  for (auto it = fileContent.data.begin(); it != fileContent.data.end(); ++it)
    error = error || !bunny_compute_effect(*it);
  if (error)
    {
      std::cerr << "We encountered an error during computing effect of " << fileContent.filename << std::endl;
      return (-1);
    }
  return (0);
}
