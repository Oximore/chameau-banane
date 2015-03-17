#include "Algorithme.hpp"

/**
 * \brief Instancie un Problème du dromadaire et des bananes
 * \param[in] distance La distance entre les deux oasis 
 * \param[in] nbb Le nombre de bananes présentes au départ sur l'oasis A
 * \param[in] nbbDMax Le nombre de bananes que peut porter le Dromadaire au maximum
 **/
Algorithme::Algorithme(kilometre distance, nombreDeBananes nbb, nombreDeBananes nbbDMax) : _depart(0), _arrivee(distance), _dromadaire(0, nbbDMax, 0) {
  assert( distance >= 0 );
  _chemin.resize(distance+1);
  _chemin.at(_depart).deposerBananes(nbb);
}

/**
 * \brief Résolve le problème du Dromadaire
 *
 * Résolve le problème du Dromadaire dans un temps résonable, ie :
 * n'attends pas que de nouveaux bananiers poussent à partir des bananes
 * initiales.
 *
 * La méthode présentée ici se résume à un parcour de graphe en
 * profondeur du bananier des possibilités. En excluant les branches à
 * prioris non utiles, c'est à dire déposer des bananes en arièrre et
 * partir vèrs l'avant en pouvnt porter plus de bananes.
 *
 **/
void Algorithme::calcul() {
  /** /

  // Tant qu'il existe des bananes
  vector<_action> bananierDesPossibilites;
  _action actionCourante, actionPrecedente;
    
  actionCourante.first = ALLER_A_PLUS_Y;
  actionCourante.second = 0;
  
  bananierDesPossibilites.push_back(actionCourante);
  
  TasDeBananes& tasDeBananesCourant;
  nombreDeBananes nbb;
  kilometre k;

  bool bananes = true;
  while (bananes) {
    tasDeBananesCourant = _tasCourant();
    actionPrecedente = bananierDesPossibilites.back();
    
    if ( actionPrecedente.first == ALLER_A_PLUS_Y ) {
      actionCourante.first = POSER_X;
      
      // ou 

      actionCourante.first = PRENDRE_X; 
    }
    


    for (nombreDeBananes nbb = 0 ; nbb <= tasDeBananesCourant.bananes() ; ++nbb ) {
      for (kilometre k = _depart ; k <= _arrivee ; ++k ) {
	_dromadaire.deposerBananes(nbb, tasDeBananesCourant);
	if (_dromadaire.peutAllerA(k)) {
	  _dromadaire.allerA(k);
	  TasDeBananes& nouveauTasDeBananes = _tasCourant();
	}
      }
    }

    //bananes = (_bananesRestantes() != 0) && !_dromadaireBloque();
    //}

  //*/
}

TasDeBananes& Algorithme::_tasCourant() {
  return _chemin.at(_dromadaire.position()); 
}

const TasDeBananes& Algorithme::_tasCourant() const {
  return _chemin.at(_dromadaire.position()); 
}


bool Algorithme::_dromadaireBloque() const {
  return (_dromadaire.bananes() == 0) && (_tasCourant().bananes() == 0);
}

nombreDeBananes Algorithme::_bananesRestantes() const {
  nombreDeBananes nbb = 0;
  for( vector<TasDeBananes>::const_iterator it = _chemin.begin() ; it != _chemin.end() ; ++it ) {
    nbb += (*it).bananes();
  }
  nbb -= _chemin.at(_arrivee).bananes();
  return nbb;
}

/**
 * \brief Affiche la solution trouvée dans le stream donné
 * \param[in, out] outstream Le ostream dans lequel on affiche la solution
 **/
void Algorithme::afficheSolution(ostream& outstream) {
  outstream << "En cours de développement." << endl;
  outstream << "Merci de patienter quelques instants." << endl;
  outstream << endl;
  outstream << "En attendant le dromadaire ayant la flemme de se taper " << (_arrivee - _depart) 
	    << " kilomètres, il a planté ses " << _chemin[_depart].bananes() 
	    << " bananes et les bananiers poussent doucement." << endl;
}
