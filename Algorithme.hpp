#ifndef ALGORITHME_HPP
#define ALGORITHME_HPP

#include <vector>

#include "Definitions.hpp"
#include "TasDeBananes.hpp"
#include "Dromadaire.hpp"

/**
 * \class Algorithme Algorithme.hpp
 * \brief Algorithme est une classe implémentant le problème du dromadaire et des bananes. 
 *
 * "Un dromadaire est à une oasis A avec 3000 bananes. Sachant qu'il
 * consome 1 banane du kilomètre et qu'il a une capacitée de
 * chargement maximale de 1000 bananes, combien de bananes peut il
 * espérer au maximum apporter à l'oasis B situé à 1000 kilomètres de
 * l'oasis A."
 * 
 **/

class Algorithme {
public:
  Algorithme(kilometre, nombreDeBananes, nombreDeBananes);

  void calcul();
  void afficheSolution(ostream&);

private:
  oasis _depart;
  oasis _arrivee;
  vector<TasDeBananes> _chemin;
  Dromadaire _dromadaire;
  
  enum _Action { PRENDRE_X, POSER_X, ALLER_A_PLUS_Y, ALLER_A_MOINS_Y};
  typedef pair<_Action, int> _action;
  vector<_action> _actions;

  TasDeBananes& _tasCourant();
  const TasDeBananes& _tasCourant() const;
  bool _dromadaireBloque() const;
  nombreDeBananes _bananesRestantes() const;
}; // Algorithme

#endif // ALGORITHME_HPP
