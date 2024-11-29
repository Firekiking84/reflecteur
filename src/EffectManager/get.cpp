// ************************************************
// 29/11/2024 02:25:55
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include	"effectManager.hh"

t_bunny_effect	*ef::EffectManager::get()
{
  t_bunny_effect	*effect;

  if (available.size() == 0)
    effect = bunny_new_effect(duration);
  else
    {
      effect = available.begin()->first;
      available.erase(effect);
    }
  busy[effect] = effect;
  return (effect);
}
