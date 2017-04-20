#ifndef CONJ_IND_HH
#define CONJ_IND_HH

#include "individu.hh"
//#include "especie.hh"
#include "Excepcio.hh"

#include <vector>
#include <map>

using namespace std;


class poblacio
{

private:

	// Tipus de modul: dades
	// Descripcio del tipus: representa un conjunt ordenat alfabeticament d'individus
	// Es poden consultar i modificar els seus elements (de tipus individu)

	especie esp;

	int nind;
	map<string,individu> vind;


	static const int MAX_NIND = 20;

	/*
	 Invariant de la representacio:
	 - vind[0..nind-1] esta ordenat alfabeticament pel nom dels individus
	 - 0 <= nind <= vind.size() = MAX_NIND  */



public:

	//Constructores

	poblacio(especie esp);
	/* Pre: cert */
	/* Post: el resultat es un conjunt d'individuus buit */

	~poblacio();

	//Modificadores

	void afegir_individu(const individu& ind);
	/* Pre: el parametre implicit no conte cap individu amb el NOM d'ind;
	 el nombre d'individus del p.i. es mes petit que la mida maxima permesa */
	/* Post: s'ha afegit l'individu ind al parametre implicit */

	void reproduir(const string mare, const string pare, const string fill); ////////////////////////////////// CONSULTAR I CORREGIR PARAMETRES
	/* Pre: el parametre implicit no conte cap individu amb el NOM de fill;
	 el nombre d'individus del p.i. es mes petit que la mida maxima permesa */
	/* Post: s'ha afegit l'individu fill al parametre implicit si:
		- mare i pare estan al p.i. i fill no esta al p.i.
		- mare i pare es poden reproduir
		- no familia entre ells tres */

	//Consultores

	int mida() const;
	/* Pre: cert */
	/* Post: el resultat es el nombre d'individuus del parametre implicit */

	int mida_maxima() const;
	/* Pre: cert */
	/* Post: el resultat es el nombre maxim d'individuus que pot arribar
	 a tenir el parametre implicit */

	especie especie() const;
	/* Pre: cert */
	/* Post: el resultat es la especie del parametre implicit */



	//////////////////////////////////////////////////////////////////////////////////////////////////////////	DUES FUNCIONS D'ARBRES

	// Lectura i escriptura
	
	void llegir();
	/* Pre: estan preparats al canal estandard d'entrada un enter (entre 0 i la
	 mida maxima permesa per a la classe), que representa el nombre d'elements
	 que llegirem, i les dades de tal nombre d'individuus diferents */
	/* Post: el parametre implicit conte el conjunt d'individuus llegits
	 del canal estandard d'entrada */

	void escriure() const;
	/* Pre: cert */
	/* Post: s'han escrit pel canal estandard de sortida els individuus del
	 parametre implicit en ordre alfabetic pel nom */

	void escriure_particular(string ind) const;
	/* Pre: cert */
	/* Post: s'han escrit pel canal estandard de sortida els parametres de
	 l'individu */

};
#endif
























