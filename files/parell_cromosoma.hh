#ifndef parell_cromosoma_hpp
#define parell_cromosoma_hpp

#include <iostream>
#include <vector>

using namespace std;

class parell_cromosoma
{
	// Tipus de modul: dades
	// Descripcio del tipus:
private:

	int i;

	int l;

	vector <bool> c1;
	vector <bool> c2;

	/*
	 Invariant de la representacio:
  */

public:

	//Constructores

	parell_cromosoma();
	/* Pre: cert */
	/* Post: el resultat es un
	 */

	parell_cromosoma(int l, int i);
	/* Pre: cert */
	/* Post: el resultat es un parell de cromosomes amb longitud l
	 */
	~parell_cromosoma();

	//Modificadores


	//Consultores

	int consultar_longitud() const;



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


#endif /* parell_cromosoma_hpp */
