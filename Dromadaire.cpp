#include "Dromadaire.hpp"

/**
 * \brief Instancie un Dromadaire portant nbb bananes situé au kilomètre k
 * \param[in] k Le kilomètre auquel est situé le Dromadaire
 * \param[in] nbbMax Le nombre maximal de bananes que peut transporter le Dromadaire
 * \param[in] nbb Le nombre de bananes portées par le Dromadaire
 */
Dromadaire::Dromadaire(kilometre k, nombreDeBananes nbbMax, nombreDeBananes nbb) : TasDeBananes(nbb), _position(k) {
  assert( nbbMax <= UINT_MAX );
  _nombreDeBananesMaximal = nbbMax;
};

/**
 * \brief Transfère nbb bananes du Dromadaire vers le TasDeBananes tdb
 * \param[in] nbb Le nombre de bananes transférées
 * \param[in, out] Le TasDeBananes
 **/
void Dromadaire::prendreBananes(nombreDeBananes nbb, TasDeBananes& tdb) {
  TasDeBananes::prendreBananes(nbb);
  tdb.deposerBananes(nbb);
}

/**
 * \brief Transfère nbb bananes du TasDeBananes tdb vers le Dromadaire
 * \param[in] nbb Le nombre de bananes transférées
 * \param[in, out] Le TasDeBananes
 **/
void Dromadaire::deposerBananes(nombreDeBananes nbb, TasDeBananes& tdb) {
  tdb.prendreBananes(nbb);
  TasDeBananes::deposerBananes(nbb);
}


/**
 * \brief Renvoie la position du Dromadaire
 * \return Le kilomètre auquel est situé le Dromadaire
 **/
kilometre Dromadaire::position() const {
  return _position;
}

/**
 * \brief Emmène le Dromadaire au kilomètre n°k
 * \param[in] k Le kilomètre
 **/
void Dromadaire::allerA(kilometre k) {
  assert( peutAllerA(k) );
  _position = k;
  TasDeBananes::prendreBananes((nombreDeBananes) abs(k-position()));
}

/**
 * \brief Retourne true si le Dromadaire peut aller au kilomètre n°k
 * \param[in] k Le kilomètre
 * \return bool True si le Dromadaire peut aller au kilomètre n°k, false sinon
 **/
bool Dromadaire::peutAllerA(kilometre k) const {
  return ((unsigned int) abs(k-position())) >= bananes();
}
