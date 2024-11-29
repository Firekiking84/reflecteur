// ************************************************
// 31/10/2024 13:43:17
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		"waveReader.hh"
#include		"midiReader.hh"

int			main(void)
{
  //  ef::WaveReader	reader("./res");
  //  ef::WaveReader	reader("./res/wav/test_lecture24.wav");
  ef::MidiReader	reader("./res/mid/test.mid");

  //  reader.print_file_sample("./res/wav/test_lecture24.wav");
  return(reader.play_all());
}
