// ************************************************
// 29/11/2024 03:29:30
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"effectManager.hh"

void		ef::EffectManager::get_all(std::vector<t_bunny_effect	*>	&effects)
{
  for (const auto& [key, value] : available)
    effects.push_back(value);
  for (const auto& [key, value] : busy)
    effects.push_back(value);
}
