// ************************************************
// 15/11/2024 15:26:28
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#ifndef				__EF_MIDI_READER_HH__

# define			__EF_MIDI_READER_HH__

# include			<fstream>
# include			<vector>
# include			<string>
# include			<iostream>

# include			<lapin.h>
# include			"note_frequencies.hh"

#define	GET_DURATION(delta, tempo, division)	(delta) * ((double)(tempo) / (division)) * 100000

namespace			ef
{
  class				MidiReader
  {
  public:
        typedef enum
      {
	UNKNOWN = -1,
	SEQUENCE = 0,
	TEXT,
	COPYRIGHT,
	TRACK_NAME,
	INSTRUMENT,
	LYRIC,
	MARKER,
	CUE_POINT,
	MIDI_CHANNEL_PREFIX,
	END,
	SET_TEMPO,
	SMPTE_OFFSET,
	TIME_SIGNATURE,
	KEY_SIGNATURE,
	SEQUENCER_SPECIFIC,
	END_META,
	PROGRAM_CHANGE_CHN_1,
	PROGRAM_CHANGE_CHN_2,
	PROGRAM_CHANGE_CHN_3,
	PROGRAM_CHANGE_CHN_4,
	PROGRAM_CHANGE_CHN_5,
	PROGRAM_CHANGE_CHN_6,
	PROGRAM_CHANGE_CHN_7,
	PROGRAM_CHANGE_CHN_8,
	PROGRAM_CHANGE_CHN_9,
	PROGRAM_CHANGE_CHN_10,
	PROGRAM_CHANGE_CHN_11,
	PROGRAM_CHANGE_CHN_12,
	PROGRAM_CHANGE_CHN_13,
	PROGRAM_CHANGE_CHN_14,
	PROGRAM_CHANGE_CHN_15,
	PROGRAM_CHANGE_CHN_16,
	NOTE_ON_CHN_1,
	NOTE_ON_CHN_2,
	NOTE_ON_CHN_3,
	NOTE_ON_CHN_4,
	NOTE_ON_CHN_5,
	NOTE_ON_CHN_6,
	NOTE_ON_CHN_7,
	NOTE_ON_CHN_8,
	NOTE_ON_CHN_9,
	NOTE_ON_CHN_10,
	NOTE_ON_CHN_11,
	NOTE_ON_CHN_12,
	NOTE_ON_CHN_13,
	NOTE_ON_CHN_14,
	NOTE_ON_CHN_15,
	NOTE_ON_CHN_16,
	NOTE_OFF_CHN_1,
	NOTE_OFF_CHN_2,
	NOTE_OFF_CHN_3,
	NOTE_OFF_CHN_4,
	NOTE_OFF_CHN_5,
	NOTE_OFF_CHN_6,
	NOTE_OFF_CHN_7,
	NOTE_OFF_CHN_8,
	NOTE_OFF_CHN_9,
	NOTE_OFF_CHN_10,
	NOTE_OFF_CHN_11,
	NOTE_OFF_CHN_12,
	NOTE_OFF_CHN_13,
	NOTE_OFF_CHN_14,
	NOTE_OFF_CHN_15,
	NOTE_OFF_CHN_16
      }				t_event_type;

    typedef struct		s_event
    {
      t_event_type		type;
      uint32_t			delta_time;
      uint32_t			size;
      uint8_t			note;
      uint8_t			velocity;
      char			*data;
    }				t_event;

    
    MidiReader();
    MidiReader(std::string		filename);
    MidiReader(std::vector<std::string>	&filenames);
    ~MidiReader();
    
    int				load_file(std::string		&filename);
    void			load_files(std::vector<std::string>	&filenames);
    void			load_dir(std::string		dirName);
    int				play_file(std::string		filename);
    int				play_all();
    int				print_filelist();
    void			print_file_sample(std::string	filename);
    int				remove_file(std::string		filename);
    int				clear();
    int				read_vlq(const char		*data,
					 uint32_t		*out);
    int				write_vlq(uint32_t		data,
					  char			*out);
    void			*next_midi_event(void		*track);
    
  private:
#pragma pack(push, 1)
    typedef struct		s_midi_header
    {
      char			id[4];
      uint32_t			size;
      uint16_t			format;
      uint16_t			nbTracks;
      uint16_t			timeDivision;
    }				t_midi_header;
#pragma pack(pop)

#pragma pack(push, 1)
    typedef struct		s_track_header
    {
      char			id[4];
      uint32_t			size;
    }				t_track_header;
#pragma pack(pop)

    typedef struct		s_track
    {
      t_track_header		header;
      char			*start_content;
    }				t_track;

    typedef struct		s_sound
    {
      int			start;
      int			stop;
      double			frequency;
      t_bunny_effect		*effect;
    }				t_sound;
    
    typedef struct		s_midi_file
    {
      std::string		filename;
      t_midi_header		header;
      uint32_t			duration;
      std::vector<t_bunny_effect *>	data;
    }				t_midi_file;

    std::vector<t_midi_file>	loaded_files;
    int				current_track;
    
    int				read_header(std::ifstream	&file,
					    t_midi_file		&fileContent);
    int				read_content(std::ifstream	&file,
					     t_midi_file	&fileContent);
    int				read_track(std::ifstream	&file,
					   t_midi_file		&fileContent);
    char			*read_event(char		*content,
					   t_event		&event);
    t_event_type		identify_event(char		*data);
    double			get_track_duration(std::vector<t_event>	&events,
						   t_midi_file	&fileContent);
    int				play(t_midi_file		&fileContent,
				     bool			wait_end = true);
    int				compile_events(t_midi_file	&fileContent,
					       std::vector<t_event>	&events);
    void			create_sound(t_sound		&sound);
    void			refresh_position(uint32_t	&n_sample,
						 uint32_t	&tempo,
						 uint32_t	&delta_time,
						 t_midi_file	&fileContent);
    double			get_ratio(int				a,
					  int				b,
					  int				x);
    std::vector<t_midi_file>::iterator	remove(std::vector<t_midi_file>::iterator	file_it);
    int				compute_file(t_midi_file	&fileContent);
    void			wait_end_effect(std::vector<t_bunny_effect *>	effects);
    t_midi_file			*get_file(std::string		filename);
  };
}

#endif	//			__EF_MIDI_READER_HH__
