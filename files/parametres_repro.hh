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

	/**@brief Longitud del cruce */
	int lenRep;

	/**@brief Parametros de reproduccion*/
	vector <pair<pair<bool,bool>,int> >pr;


public:

	//Constructores

	/** @brief Creadora por defecto.
	 Se ejecuta automáticamente al declarar una especie.
	 \pre <em>cierto</em>
	 \post El resultado es una especie sin descripcion */
	par_rep(especie &esp);

	/** @brief Destructora por defecto.
	 \pre <em>cierto</em>
	 \post Destruye la especie*/
	~par_rep();

	//Consultores

	/** @brief Consulta el numero de pares de cromosomas no sexuales.
	 \pre <em>cierto</em>
	 \post El resultado es el numero de pares de cromosomas normales
	 \coste Constante  */
	int consultar_punt_tall(int i) const;

	/** @brief Consula el ovulo y cromosoma a cruzar.
	 \pre <em>cierto</em>
	 \post El resultado es la posicion del ovulo y el espermatozoide*/
	pair<bool,bool> consultar_ovul_esper(int i) const;

	/** @brief Consulta la longitud del cruce.
	 \pre <em>cierto</em>
	 \post El resultado es la longitud del cruce */
	int consultar_len_rep() const;

	// Lectura i escriptura

	/** @brief Consulta la longitud del cruce.
	 \pre <em>cierto</em>
	 \post El p.i. pasa a contener los parametros leidos por el canal estandar de entrada */
	void llegir_parametres_reproduccio();
	
	
};

#endif
