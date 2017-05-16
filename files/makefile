OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o poblacio.o individu.o especie.o parametres_repro.o
	g++ -o program.exe program.o poblacio.o especie.o individu.o parametres_repro.o
	rm *.o

program.o: program.cc poblacio.hh individu.hh especie.hh parametres_repro.hh
	g++ -c program.cc $(OPCIONS)

poblacio.o: poblacio.cc poblacio.hh 
	g++ -c poblacio.cc $(OPCIONS)

individu.o: individu.cc individu.hh 
	g++ -c individu.cc $(OPCIONS)

especie.o: especie.cc especie.hh
	g++ -c especie.cc $(OPCIONS)

parametres_repro.o: parametres_repro.cc parametres_repro.hh
	g++ -c parametres_repro.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
