/** @file poblacio.hh
 @brief Especificación de la clase poblacio
 */

#ifndef CONJ_IND_HH
#define CONJ_IND_HH

#include "individu.hh"
#include "especie.hh"

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
	poblacio(especie esp);

	/** @brief Destructora por defecto.
	 \pre <em>cierto</em>
	 \post Se destruye la especie
	 \coste Constante  */
	~poblacio();

	//Modificadores

	/** @brief Añade un individuo a la poblacion
	 \pre <em>No existe un individuo con el nombre de ind y el numero de individuos del p.i. es mas pequeño que el tamaño permitido ind</em>
	 \post El parámetro implícito pasa a contener el individuo
	 \coste Constante */
	void afegir_individu(const individu& ind);

	/** @brief Reproduce dos individuos y añade el individuo resultante a la poblacion.
	 \pre <em>Los  dos primeros nombres si estan entre los individuos del p.i. (existen) y el tercero no esta (no existe). Deben ser de sexo opuesto, no ser hermanos ni por parte de padre ni de madre, y no ser ninguno de los dos antecesor del otro</em>
	 \post El parámetro implícito pasa a contener el individuo fill fruto de la reproduccion de mare y pare
	 \coste Constante */
	void reproduir(const string mare, const string pare, const string fill); ////////////////////////////////// CONSULTAR I CORREGIR PARAMETRES
	
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


	// Lectura i escriptura
	
	/** @brief Operación de lectura.
	 \pre <em>Estan preparados en el canal estandar de entrada un entero que representa el numero de individuos que se van a leer y dichos individuos</em>
	 \post Lee un conjunto de individuos por el canal estándar de entrada
	 \coste */
	void llegir();

	/** @brief Operación de escritura.
	 \pre <em>cierto</em>
	 \post Escribe el nombre, los cromosomas sexuales y los padres (si tiene) del parámetro implícito por el canal estándar de salida
	 \coste */
	void escriure() const;

	/** @brief Operación de escritura.
	 \pre <em>Existe un individuo con el nombre ind en la poblacion</em>
	 \post Escribe el nombre, y su codigo genetico por el canal estándar de salida
	 \coste */
	void escriure_particular(string ind) const;

};

#endif
























