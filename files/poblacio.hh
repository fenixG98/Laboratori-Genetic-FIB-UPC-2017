/** @file poblacio.hh
 @brief Especificación de la clase poblacio
 */

#ifndef CONJ_IND_HH
#define CONJ_IND_HH

#include "individu.hh"
//#include "arbre_parcial.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <string>
#endif

/** @class poblacio
 @brief Representa una poblacion de individuos de una misma especie.

 Solo puede contener individuos de una misma especie. Puede usarse para realizar experimentos con mas de un individuo.
 */

class poblacio
{

private:

	int nind;

	struct persona
	{
		individu ind;
		map<string,persona>::const_iterator mare;
		map<string,persona>::const_iterator pare;
	};

	map<string,persona> vind;

	static const int MAX_NIND = 200;

public:

	//Constructores

	/** @brief Creadora por defecto.
	 Se ejecuta automáticamente al declarar una poblacion.
	 \pre <em>cierto</em>
	 \post El resultado es una poblacion de una determinada especie pero sin individuos.
	 \coste Constante */
	poblacio();

	/** @brief Destructora por defecto.
	 \pre <em>cierto</em>
	 \post Se destruye la especie
	 \coste Constante  */
	~poblacio();

	//Modificadores

	/** @brief Añade un individuo a la poblacion
	 \pre <em>No existe un individuo con el nombre de nom y el numero de individuos del p.i. es mas pequeño que el tamaño permitido ind</em>
	 \post El parámetro implícito pasa a contener el individuo
	 \coste Constante */
	void afegir_individu(const string nom, const individu& ind);

	/** @brief Completa un arbol parcial
	 \pre <em>cierto</em>
	 \post se completa el arbol si es arbol parcial
	 \coste Constante */
	//bool completar_ap(ArbreP ap);
	
	//Consultores

	/** @brief Consulta el numero de individuos de la poblacion.
	 \pre <em>cierto</em>
	 \post El resultado es el numero de de individuos de la poblacion
	 \coste Constante  */
	int mida() const;

	/** @brief Consulta el numero maximo de individuos que puede contener la poblacion.
	 \pre <em>cierto</em>
	 \post El resultado es el numero maximo de de individuos que puede contener la poblacion
	 \coste Constante  */
	int mida_maxima() const;

	/** @brief Consulta si los dos parametros son compatibles para la reproducción.
	 \pre <em>cierto</em>
	 \post El resultado es true si son de distitno genero.
	 \coste Constante  */
	bool compatibles(const string a,const string b);

	/** @brief Consulta el individuo con nombre nom.
	 \pre <em>El individuo nom existe en l apoblacion</em>
	 \post El resultado es el individuo de nombre nom
	 \coste Constante  */
	individu individu_nom(const string nom) const;

	/** @brief Consulta el individuo con nombre nom.
	 \pre <em>cierto</em>
	 \post El resultado es true si el individuo existe en la poblacion
	 \coste Constante  */
	bool existeix_individu(const string nom) const;

	// Lectura i escriptura
	
	/** @brief Operación de lectura.
	 \pre <em>Estan preparados en el canal estandar de entrada un entero que representa el numero de individuos que se van a leer y dichos individuos</em>
	 \post Lee un conjunto de individuos por el canal estándar de entrada
	 \coste */
	void llegir(const especie &esp);

	/** @brief Operación de escritura.
	 \pre <em>cierto</em>
	 \post Escribe el nombre, los cromosomas sexuales y los padres (si tiene) del parámetro implícito por el canal estándar de salida */
	void escriure() const;

	/** @brief Operación de escritur del arbre genealogic.
	 \pre <em>cierto</em>
	 \post Escribe el grafo-arbol(binario) de sus ascendientes en preorden.
	 \coste */
	void escriure_arbre(const string nom) const;

};

#endif
























