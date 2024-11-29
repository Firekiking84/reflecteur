// ************************************************
// 29/11/2024 02:12:50
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#ifndef			__EF_EFFECT_MANAGER_HH__

# define		__EF_EFFECT_MANAGER_HH__

# include		<map>
#include		<vector>

# include		<lapin.h>

namespace		ef
{
  class			EffectManager
  {
  public:
    EffectManager(uint32_t		_duration);
    ~EffectManager();

    t_bunny_effect	*get();
    void	        free(t_bunny_effect	*effect);
    void		get_all(std::vector<t_bunny_effect	*>	&effects);
  private:
    uint32_t				duration;
    std::map<t_bunny_effect	*, t_bunny_effect *>	available;
    std::map<t_bunny_effect	*, t_bunny_effect *>	busy;
  };
}

#endif	//		__EF_EFFECT_MANAGER_HH__
