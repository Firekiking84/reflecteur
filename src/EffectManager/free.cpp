// ************************************************
// 29/11/2024 02:33:19
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"effectManager.hh"

void		ef::EffectManager::free(t_bunny_effect	*effect)
{
  auto		it = busy.find(effect);

  if (it != busy.end())
    {
      available[it->first] = it->second;
      busy.erase(it);
    }
}
