// ************************************************
// 31/10/2024 17:01:54
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		"waveReader.hh"

int			ef::WaveReader::set_sounds(t_wav_file	&fileContent)
{
  size_t		i;
  t_bunny_effect	*channel;

  for (i = 0; i < fileContent.header.NbrCanaux; i += 1)
    {
      channel = bunny_create_effect(fileContent.info.duration, fileContent.info.samplePerSec);
      if (!channel)
	{
	  std::cerr << "Failed to create channel for : " << fileContent.filename << std::endl;
	  return (-1);
	}
      fileContent.data.push_back(channel);
       if (fileContent.header.NbrCanaux == 6)
	{
	  if (i == 0)
	    channel->sound.position[1] = -DISTANCE_SOUND / 2;
	  else if (i == 1)
	    channel->sound.position[1] = -DISTANCE_SOUND;
	  else if (i == 3)
	    channel->sound.position[1] = DISTANCE_SOUND / 2;
	  else if (i == 4)
	    channel->sound.position[1] = DISTANCE_SOUND;
	  else if (i == 5)
	    channel->sound.position[2] = DISTANCE_SOUND;
	}
      else if (fileContent.header.NbrCanaux == 4 || fileContent.header.NbrCanaux == 5)
	{
	  if (i == 0)
	    {
	      channel->sound.position[0] = DISTANCE_SOUND;
	      channel->sound.position[1] = -DISTANCE_SOUND;
	    }
	  else if (i == 1)
	    {
	      channel->sound.position[0] = DISTANCE_SOUND;
	      channel->sound.position[1] = DISTANCE_SOUND;
	    }
	  else if (i == 2)
	    {
	      channel->sound.position[0] = -DISTANCE_SOUND;
	      channel->sound.position[1] = -DISTANCE_SOUND;
	    }
	  else if (i == 3)
	    {
	      channel->sound.position[0] = -DISTANCE_SOUND;
	      channel->sound.position[1] = DISTANCE_SOUND;
	    }
	  else if (i == 4)
	    channel->sound.position[2] = DISTANCE_SOUND;
	}
      else if (fileContent.header.NbrCanaux == 3)
	{
	  if (i == 0)
	    channel->sound.position[1] = -DISTANCE_SOUND;
	  else if (i == 2)
	    channel->sound.position[1] = DISTANCE_SOUND;
	}
      else if (fileContent.header.NbrCanaux == 2)
	{
	  if (i == 0)
	    channel->sound.position[1] = -DISTANCE_SOUND;
	  else
	    channel->sound.position[1] = DISTANCE_SOUND;
	}
    }
  return(0);
}
