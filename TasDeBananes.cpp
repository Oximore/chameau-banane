#include "TasDeBananes.hpp"

/**
 * \brief Instancie un TasDeBananes contenant nbb bananes
 * \param[in] nbb Nombre de bananes que contient le TasDeBananes
 **/
TasDeBananes::TasDeBananes(nombreDeBananes nbb) : _bananes(nbb),  _nombreDeBananesMaximal(UINT_MAX) {}

/**
 * \brief Renvoie le nombre de banane du TasDeBananes
 * \return Le nombre de bananes du TasDeBanane
 **/
nombreDeBananes TasDeBananes::bananes() const {
  return _bananes;
}

/**
 * \brief Enlève nbb bananes du TasDeBananes
 * \param[in] nbb Le nombre de bananes à enlever du TasDeBananes
 **/
void TasDeBananes::prendreBananes(nombreDeBananes nbb) {
  assert(_bananes >= nbb);
  _bananes -= nbb;
}

/**
 * \brief Rajoute nbb bananes au TasDeBananes
 * \param[in] nbb Le nombre de bananes à ajouter au TasDeBananes
 **/
void TasDeBananes::deposerBananes(nombreDeBananes nbb) {
  assert(_nombreDeBananesMaximal - _bananes >= nbb);
  _bananes += nbb;
}
