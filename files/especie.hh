#ifndef ESPECIE_HH
#define ESPECIE_HH


#include <iostream>
#include <vector>


using namespace std;


class especie
{
	// Tipus de modul: dades
	// Descripcio del tipus:
private:


	int N;
	vector<int> l;
	int lx;
	int ly;


	/*
	 Invariant de la representacio:
  */

public:

	//Constructores

	especie();
	/* Pre: cert */
	/* Post: el resultat es un 
	 */
	~especie();

	//Modificadores


	//Consultores

	int consultar_numero_parells() const;


	int consultar_longitud_x() const;


	int consultar_longitud_y() const;


	vector <int> consultar_longitud() const;

	// Lectura i escriptura
	
	void llegir();
	/* Pre: estan preparats al canal estandard d'entrada un enter , que representa el nombre de parells
	 de cromosomes que llegirem, i les mides de tals cromosomes*/
	/* Post: el parametre implicit conte la informacio llegida del canal estandard d'entrada */

	void escriure() const;
	/* Pre: cert */
	/* Post: s'han escrit pel canal estandard de sortida els parametres de
	 la especie*/

};
#endif
