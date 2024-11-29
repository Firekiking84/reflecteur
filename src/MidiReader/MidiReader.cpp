// ************************************************
// 15/11/2024 16:08:15
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		"midiReader.hh"

ef::MidiReader::MidiReader(std::vector<std::string>	&filenames)
{
  load_files(filenames);
}

ef::MidiReader::MidiReader(std::string			filename)
{
  std::vector<std::string>	filenames;

  filenames.push_back(filename);
  load_files(filenames);
}

ef::MidiReader::MidiReader()
{
}

ef::MidiReader::~MidiReader()
{
  clear();
}
