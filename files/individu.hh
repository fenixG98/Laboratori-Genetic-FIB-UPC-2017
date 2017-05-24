/** @file individu.hh
 @brief Especificacion de la clase c_individu
 */

#ifndef INDIVIDU_HH
#define INDIVIDU_HH

#include "especie.hh"
#include "parametres_repro.hh"


#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
#include <vector>
#endif

/** @class c_individu
 @brief Representa un individuo.

 Contiene la informacion de un individuo (nombre, sexo, codigo genetico y si tiene padres).
 Puede usarse para realizar experimentos.*/
using namespace std;

class c_individu
{

private:
	/**@brief Informacion genetica del individuo.*/
	vector<pair<list<bool>, list<bool> > > COD_GEN ;

	/**@brief Sexo del individuo.*/
	bool SEXE;

	/**@brief Informacion sobre si tiene padres o no.*/
	bool amb_pares;

public:

	//Constructores

	/** @brief Creadora por defecto.
	 Se ejecuta automaticamente al declarar una poblacion.
	 \pre <em>cierto.</em>
	 \post El resultado es una individuo sin especie , sin nombre ni codigo genetico ni padres.*/
	c_individu();

	/** @brief Creadora a partir de dos individuos.
	 Se ejecuta automaticamente al declarar una poblacion.
	 \pre <em>individuo a es compatible con b para la reproduccion.</em>
	 \post El resultado es un individuo fruto de la reproduccion sexual de a y b. */
	c_individu(par_rep &pr, const c_individu &a, const c_individu &b);

	/** @brief Destructora por defecto.
	 \pre <em>cierto.</em>
	 \post Se destruye el individuo. */
	~c_individu();

	//Consultores

	/** @brief Consulta el sexo del individuo.
	 \pre <em>El p.i. tiene sexo.</em>
	 \post El resultado es el sexo del individuo.*/
	bool consultar_SEXE() const;

	/** @brief Consulta si tiene padres el individuo.
	 \pre <em>cierto.</em>
	 \post El resultado es true si tiene padres. */
	bool te_pares() const;

	// Lectura i escriptura

	/** @brief Operación de lectura.
	 \pre <em>Estan preparados en el canal estandar de entrada el cromosomas sexual Y y el codigo genetico</em>
	 \post Lee un conjunto de individuos por el canal estándar de entrada
	 \coste */
	void llegir(const c_especie &esp);

	/** @brief Operacion de escritura.
	 \pre <em>cierto.</em>
	 \post Escribe el nombre, y su codigo genetico por el canal estandar de salida.*/
	void escriure() const;

private:

	/** @brief Cruza dos listas segun unos parametros.
	 \pre <em>l1 y l2 son listas no vacias y l <= n. </em>
	 \post Devuelve una lista resultante del cruce de l1 y l2. */
	list<bool> creurar_llistes(int l, int n, const list<bool> &l1, const list<bool> &l2);
};
#endif
