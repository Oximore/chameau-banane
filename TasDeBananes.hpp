#ifndef TAS_DE_BANANES_HPP
#define TAS_DE_BANANES_HPP

#include "Definitions.hpp"

/**
 * \class TasDeBananes TasDeBananes.hpp
 * \brief Un TasDeBananes est consitué un monticule de bananes, plus ou moins nombeuses
 *
 * Un TasDeBananes peut contenir un nombre infini de bananes (dans les limites informatique, limité à UINT_MAX).
 * Les bananes peuvent y rester un temps indéfini, au pire c'est toujours bon flambée.
 **/

class TasDeBananes {
public:
  TasDeBananes(nombreDeBananes nbb = 0);
  
  nombreDeBananes bananes() const;
  void prendreBananes(nombreDeBananes);
  void deposerBananes(nombreDeBananes);

protected:
  nombreDeBananes _bananes;
  nombreDeBananes _nombreDeBananesMaximal;
}; // TasDeBananes

#endif // TAS_DE_BANANES_HPP
