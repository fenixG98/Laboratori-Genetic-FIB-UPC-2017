OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o poblacio.o individu.o especie.o parametres_repro.o arbre_parcial.o
	g++ -o program.exe program.o poblacio.o especie.o individu.o parametres_repro.o arbre_parcial.o
	rm *.o

program.o: program.cc poblacio.hh individu.hh especie.hh parametres_repro.hh arbre_parcial.hh
	g++ -c program.cc $(OPCIONS)

poblacio.o: poblacio.cc poblacio.hh
	g++ -c poblacio.cc $(OPCIONS)

individu.o: individu.cc individu.hh
	g++ -c individu.cc $(OPCIONS)

especie.o: especie.cc especie.hh
	g++ -c especie.cc $(OPCIONS)

parametres_repro.o: parametres_repro.cc parametres_repro.hh
	g++ -c parametres_repro.cc $(OPCIONS)

arbre_parcial.o: arbre_parcial.cc arbre_parcial.hh Arbre.hh
	g++ -c arbre_parcial.cc $(OPCIONS)

clean:
	rm *.txt
	rm *.exe

practica.tar:
	tar -cvf practica.tar *.hh *.cc makefile

practica_ultima.tar:
	tar -cvf practica.tar *.hh *.cc html.zip makefile
