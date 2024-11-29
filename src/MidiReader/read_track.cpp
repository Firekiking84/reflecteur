// ************************************************
// 27/11/2024 16:35:33
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		"midiReader.hh"

#include		<arpa/inet.h>

int			ef::MidiReader::read_track(std::ifstream	&file,
						   t_midi_file		&fileContent)
{
  t_track		track;

  file.read(reinterpret_cast<char *>(&track.header), sizeof(track.header));
  track.header.size =  ntohl(track.header.size);
  if (strncmp(track.header.id, "MTrk", 4) != 0)
    {
      std::cerr << "I'm lost in file : " << fileContent.filename << std::endl;
      return (0);
    }
  char			*content;
  
  try {
    track.start_content = new char[track.header.size];
  } catch (const std::bad_alloc& e) {
    std::cerr << "Allocation error : " << e.what() << std::endl;
    return (-1);
  }
  t_event		event;
  std::vector<t_event>	events;

  content = track.start_content;
  file.read(track.start_content, track.header.size);
  while ((content - track.start_content) < track.header.size)
    {
      content = read_event(content, event);
      if (!content)
	{
	  std::cerr << "We get lost in a track in the file > " << fileContent.filename << std::endl;
	  return (-1);
	}
      events.push_back(event);
    }
  fileContent.duration = get_track_duration(events, fileContent);
  compile_events(fileContent, events);
  delete[] track.start_content;
  return (0);
}
