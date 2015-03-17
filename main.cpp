#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Definitions.hpp"
#include "Algorithme.hpp"

int main() {
  
  Algorithme bananeDromadaire(1000, 3000, 1000);
  
  bananeDromadaire.calcul();
  bananeDromadaire.afficheSolution(cout);
  
  return EXIT_SUCCESS;
}
