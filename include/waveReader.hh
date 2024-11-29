// ************************************************
// 31/10/2024 10:47:24
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#ifndef			__EF_REFLECTEUR_HH__

# define		__EF_REFLECTEUR_HH__

# include		<vector>
# include		<string>
# include		<iostream>
# include		<lapin.h>

# define		DISTANCE_SOUND 2

namespace		ef
{  
  class			WaveReader
  {
  public:
    WaveReader(std::vector<std::string>	filenames);
    WaveReader(std::string	filename);
    WaveReader();
    ~WaveReader();

    int				load_file(std::string		&filename);
    void			load_files(std::vector<std::string>	&filenames);
    void			load_dir(std::string		dirName);
    int				play_file(std::string		filename);
    int				play_all();
    int				print_filelist();
    void			print_file_sample(std::string	filename);
    int				remove_file(std::string		filename);
    int				clear();
 
  private:
#pragma pack(push, 1)
    typedef struct		s_data_header
    { // Bloc des données
      char			DataBlocId[4];
      uint32_t			DataSize;      
    }				t_data_header;
#pragma pack(pop)
#pragma pack(push, 1)
    typedef struct		s_wav_header
    {
      // Bloc de déclaration d'un fichier au format WAVE
      char			FileTypeBlocID[4];
      uint32_t			FileSize;
      char			FileFormatID[4];

      // Bloc décrivant le format audio
      char			FormatBlocID[4];
      uint32_t			BlocSize;
      uint16_t			AudioFormat;
      uint16_t			NbrCanaux;
      uint32_t			Frequence;
      uint32_t			BytePerSec;
      uint16_t			BytePerBloc;
      uint16_t			BitsPerSample;
      
      t_data_header		data;
    }				t_wav_header;
#pragma pack(pop)
    typedef struct		s_wav_info
    {
      size_t			BytePerSample;
      size_t			samplePerSec;
      size_t			nbSample;
      double			duration;
    }				t_wav_info;

    typedef struct		s_wav_file
    {
      std::string		filename;
      t_wav_header		header;
      t_wav_info		info;
      std::vector<t_bunny_effect *>	data;
    }				t_wav_file;

    std::vector<t_wav_file>	loaded_files;

    int				read_header(std::ifstream	&file,
					    t_wav_file		&fileContent);
    int				read_content(std::ifstream	&file,
					     t_wav_file		&fileContent);
    int				compressSample(int64_t		sample,
					       uint16_t		nbBits);
    int				set_sounds(t_wav_file		&fileContent);
    int				compute_file(t_wav_file		&fileContent);
    int				play(t_wav_file			&fileContent,
				     bool			wait_end = true);
    t_wav_file			*get_file(std::string		filename);
    std::vector<t_wav_file>::iterator	remove(std::vector<t_wav_file>::iterator	file_it);
    void			wait_end_effect(std::vector<t_bunny_effect *>	effects);
  };
}

#endif	//		__EF_REFLECTEUR_HH__
