#ifndef DROMADAIRE_HPP
#define DROMADAIRE_HPP

#include "Definitions.hpp"
#include "TasDeBananes.hpp"

/**
 * \class Dromadaire Dromadaire.hpp
 * \brief Un Dromadaire à généralement deux bosses.
 *
 * Un Dromadaire peut porter un nombre de bananes (positif ou nul).
 * Il possède cependant une capacité de fret maximal.
 * Un dromadaire est situé à un certain kilomètre.
 **/

class Dromadaire : public TasDeBananes {
public:
  Dromadaire(kilometre k, nombreDeBananes nbbMax, nombreDeBananes nbb = 0);
  
  void prendreBananes(nombreDeBananes, TasDeBananes&);
  void deposerBananes(nombreDeBananes, TasDeBananes&);

  kilometre position() const;
  void allerA(kilometre);
  bool peutAllerA(kilometre) const;

private:
  kilometre _position;
}; // Dromadaire

#endif // DROMADAIRE_HPP
