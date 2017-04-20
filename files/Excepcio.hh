#ifndef EXCEPCIO  // per evitar fer mes d'un include d'aquest fitxer
#define EXCEPCIO

#include <exception>

using namespace std;

/* Classe Excepcio */
class Excepcio: public exception {
public:
	Excepcio(const char* mot) : exception(), mensaje(mot) {}
	const char* what() const throw() {return mensaje;};
private:
	const char* mensaje;
};
/* Fi classe Excepcio*/

#endif

