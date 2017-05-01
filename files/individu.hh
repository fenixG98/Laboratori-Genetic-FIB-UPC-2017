/** @file individu.hh
 @brief Especificación de la clase individu
 */

#ifndef INDIVIDU_HH
#define INDIVIDU_HH

#include "especie.hh"
//#include "Arbre.hh"


#ifndef NO_DIAGRAM 
#include <iostream>
#include <list>
#endif

/** @class individu
 @brief Representa un individuo.

 Contiene la informacion de un individuo (nombre, sexo, codigo genetico y padres) de la especie de su poblacion. Puede usarse para realizar experimentos con un solo individuo.*/
using namespace std;

class individu
{

private:

	vector<pair<list<bool>, list<bool> > > COD_GEN ;

	char sex1;
	char sex2;
	bool SEXE;

	bool amb_pare;
	bool amb_mare;

public:

	//Constructores

	/** @brief Creadora por defecto.
	 Se ejecuta automáticamente al declarar una poblacion.
	 \pre <em>cierto</em>
	 \post El resultado es una individuo sin especie , sin nombre ni codigo genetico ni padres.
	 \coste Constante */
	individu();

	/** @brief Creadora a partir de dos individuos.
	 Se ejecuta automáticamente al declarar una poblacion.
	 \pre <em> individuo a es compatible con b para la reproduccion</em>
	 \post El resultado es un individuo fruto de la reproduccion sexual de a y b.
	 \coste Constante */
	individu(const vector<pair<pair<bool, bool>, int> > &pt, const individu a, const individu b, especie esp);


	/** @brief Destructora por defecto.
	 \pre <em>cierto</em>
	 \post Se destruye el individuo
	 \coste Constante  */
	~individu();

	//Consultores

	/** @brief Consulta el sexo del individuo.
	 \pre <em>El p.i. tiene sexo</em>
	 \post El resultado es el sexo del individuo
	 \coste Constante  */
	bool consultar_SEXE() const;

	/** @brief Consulta si tiene madre el individuo.
	 \pre <em>cierto</em>
	 \post El resultado es true si tiene padre
	 \coste Constante  */
	bool te_pare() const;

	

	/** @brief Consulta sie tiene madre el individuo.
	 \pre <em>cierto</em>
	 \post El resultado es true si tiene madre
	 \coste Constante  */
	bool te_mare() const;

	// Lectura i escriptura

	/** @brief Operación de lectura.
	 \pre <em>Estan preparados en el canal estandar de entrada el cromosomas sexual Y y su codigo genetico</em>
	 \post Lee un conjunto de individuos por el canal estándar de entrada
	 \coste */
	void llegir(const especie &esp);

	/** @brief Operación de escritura.
	 \pre <em>cierto</em>
	 \post Escribe el nombre, y su codigo genetico por el canal estándar de salida
	 \coste */
	void escriure(const especie &esp) const;

};
#endif
