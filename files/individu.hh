#ifndef INDIVIDU_HH
#define INDIVIDU_HH

#include <iostream>
#include <vector>
#include "especie.hh"
#include "Excepcio.hh"


//#include "parell_cromosoma.hh"

using namespace std;


class individu
{

	// Tipus de modul: dades
	// Descripcio del tipus: conte el NOM, que seria un string, codi genetic (COD_GEN)
	//que seria un vector, SEXE, que seria un string,
	// i descripcio de la especie (EspInd) d'un individuu, que seria uns especie,
	//que serien strings, seguit de si te mare i pare (amb_pare, amb_mare), que serien
	//boleans i finalment els seus respectius (NOM_MARE, NOM_PARE) que serien punters
	// que apunten a unaltre individu
private:

	string NOM;

	vector<pair<vector<int>, vector<int>>> COD_GEN ;

	especie EspInd;

	char sex1 = 'X';
	char sex2;

	string SEXE;

	bool amb_pare;
	individu* PARE;
	bool amb_mare;
	individu* MARE;


	/*
	 Invariant de la representacio:
	 - Amb NOM, COD_GEN i SEXE i EspInd
	 - Si amb_pare lavors NOM_PARE = (string)
	 - Si amb_mare lavors NOM_MARE = (string)

  */

public:
	//Constructores

	individu();
	/* Pre: cert */
	/* Post: el resultat es un individuu sense NOM, sense CODI_GEN, sense SEXE,
	 pare = mare = false */

	individu(especie esp);
	/* Pre: cert */
	/* Post: el resultat es un individuu sense NOM, sense CODI_GEN, sense SEXE,
	 pare = mare = false */


	~individu();

	//Modificadores
	void afegir_especie(const especie& esp);
	

	//Consultores

	string consultar_NOM() const;
	/* Pre: cert  */
	/* Post: el resultat es el NOM del parametre implicit */

	string consultar_SEXE() const;
	/* Pre: cert  */
	/* Post: el resultat es el SEXE del parametre implicit */


	bool te_pare() const;
	/* Pre: cert  */
	/* Post: el resultat es true si te pare el parametre implicit, false si no en te */

	individu consultar_MARE() const;
	/* Pre: cert  */
	/* Post: el resultat es l'individu MARE del parametre implicit */


	bool te_mare() const;
	/* Pre: cert  */
	/* Post: el resultat es true si te mare el parametre implicit, false si no en te */

	individu consultar_PARE() const;
	/* Pre: cert  */
	/* Post: el resultat es l'individu PARE del parametre implicit */



	// Lectura i escriptura

	void llegir();
	/* Pre:  hi ha preparats al canal estandard d'entrada un string no buit
	 i un altre string no buit*/
	/* Post: el parametre implicit passa a tenir els atributs llegits
	 del canal estandard d'entrada */

	void escriure() const; 	/* Pre: cert */
	/* Post: s'han escrit els atributs del parametre implicit
	 al canal estandard de sortida */


	void escriure_particular() const;
	/* Pre: cert */
	/* Post: s'han escrit els atributs del parametre implicit
	 al canal estandard de sortida */

};
#endif
