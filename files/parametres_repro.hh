/** @file parametres_repro.hh
 @brief Especificación de la clase parametres_reproduccio
 */

#ifndef PARAM_REPRO_HH
#define PARAM_REPRO_HH

#include "especie.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif


using namespace std;
class par_rep
{

private:

	int lenRep;
	vector <pair<pair<bool,bool>,int> >pr;


public:

	//Constructores

	/** @brief Creadora por defecto.
	 Se ejecuta automáticamente al declarar una especie.
	 \pre <em>cierto</em>
	 \post El resultado es una especie sin descripcion
	 \coste Constante */
	par_rep(especie &esp);

	/** @brief Destructora por defecto.
	 \pre <em>cierto</em>
	 \post Destruye la especie
	 \coste Constante*/
	~par_rep();

	//Consultores

	/** @brief Consulta el numero de pares de cromosomas no sexuales.
	 \pre <em>cierto</em>
	 \post El resultado es el numero de pares de cromosomas normales
	 \coste Constante  */
	int consultar_punt_tall(int i) const;

	pair<bool,bool> consultar_ovul_esper(int i);

	/** @brief Consulta la longitud del cromosoma sexual Y.
	 \pre <em>cierto</em>
	 \post El resultado es la longitud del cromosoma Y
	 \coste Constante  */
	int consultar_len_rep() const;


	// Lectura i escriptura


	void llegir_parametres_reproduccio();
	
	
};

#endif
