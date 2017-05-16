/** @file poblacio.hh
 @brief Especificación de la clase poblacio
 */

#ifndef CONJ_IND_HH
#define CONJ_IND_HH

#include "individu.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <string>
#include <queue>
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

	void r_arbre_genealogic(queue<string> &q, int cont);

	bool r_compatibles(const string a,const string b);

	bool comprobar_ascendent(string x, string marca);

	void generar_arbre_genealogic(list<string> &l, map<string,persona>::const_iterator it);



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


	void afegir_pares(string a, string b, string c);

	//Consultores

	/** @brief Consulta si los dos parametros son compatibles para la reproducción.
	 \pre <em>cierto</em>
	 \post El resultado es true si son de distitno genero.
	 \coste Constante  */
	bool compatibles(const string a,const string b);

	/** @brief Consulta el individuo con nombre nom.
	 \pre <em>El individuo nom existe en la poblacion</em>
	 \post El resultado es el individuo de nombre nom
	 \coste Constante  */
	individu individu_nom(const string nom) const;

	/** @brief Consulta el individuo con nombre nom.
	 \pre <em>cierto</em>
	 \post El resultado es true si el individuo existe en la poblacion
	 \coste Constante  */
	bool existeix_individu(const string nom) const;

	//bool completar_ap(ArbreP apr);

	list<string> arbre_genealogic(const string nom);



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
	void escriure_arbre_genealogic(const string nom);



};

#endif
