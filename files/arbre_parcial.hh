/** @file especie.hh
 @brief Especificación de la clase especie
 */

#ifndef ARBRE_PARCIAL_HH
#define ARBRE_PARCIAL_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include "Arbre.hh"
#endif

/** @class especie
 @brief Representa una especie de individuo.

 Puede contener una descripcion de la especie. Puede usarse para crear una poblacion de esta especie.
 */
using namespace std;
class arbre_parcial
{

private:

	Arbre<string> ap;

	void llegir_arbre_string(Arbre<string>& a);

	void escriure_arbre_string(Arbre<string>& a);

	bool r_es_parcial ( Arbre<string> &a,  Arbre<string> &b, Arbre<string> &res);

	void fills_mod(Arbre<string> &a, Arbre<string> &b);

public:

	//Constructores
	
	arbre_parcial();

	arbre_parcial(const Arbre<string> &copia);

	~arbre_parcial();

	string consultar_NOM() const;

	bool es_parcial(const arbre_parcial &ag);

	void llegir();

	void escriure();
};

#endif
