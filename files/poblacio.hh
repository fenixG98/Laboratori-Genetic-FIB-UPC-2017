/** @file poblacio.hh
 @brief Especificación de la clase poblacio
 */

#ifndef CONJ_IND_HH
#define CONJ_IND_HH

#include "individu.hh"

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

	especie esp;
	int nind;
	map<string,individu> vind;
	static const int MAX_NIND = 200;

public:

	//Constructores

	/** @brief Creadora por defecto.
	 Se ejecuta automáticamente al declarar una poblacion.
	 \pre <em>cierto</em>
	 \post El resultado es una poblacion de una determinada especie pero sin individuos.
	 \coste Constante */
	poblacio(const especie &esp);

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

	/** @brief Reproduce dos individuos y añade el individuo resultante a la poblacion.
	 \pre <em>Los  dos primeros nombres si estan entre los individuos del p.i. (existen) y el tercero no esta (no existe). Deben ser de sexo opuesto, no ser hermanos ni por parte de padre ni de madre, y no ser ninguno de los dos antecesor del otro</em>
	 \post El parámetro implícito pasa a contener el individuo fill fruto de la reproduccion de mare y pare
	 \coste Constante */
	void reproduir(const string mare, const string pare, const string fill);
	
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

	/** @brief Consulta el individuo con nombre nom.
	 \pre <em>El individuo nom existe en l apoblacion</em>
	 \post El resultado es el individuo
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
	void llegir();

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
























