OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o Cjt_estacions.o Estacion.o Cjt_bicis.o Bici.o
	g++ -o program.exe program.o Cjt_estacions.o Estacion.o Cjt_bicis.o Bici.o $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

Cjt_estacions.o: Cjt_estacions.cc Cjt_estacions.hh 
	g++ -c Cjt_estacions.cc $(OPCIONS)

Estacion.o: Estacion.cc Estacion.hh
	g++ -c Estacion.cc $(OPCIONS)

Cjt_bicis.o: Cjt_bicis.cc Cjt_bicis.hh
	g++ -c Cjt_bicis.cc $(OPCIONS)

Bici.o: Bici.cc Bici.hh 
	g++ -c Bici.cc $(OPCIONS)

tar:
	tar -cvf practica.tar program.cc Cjt_estacions.cc Cjt_bicis.cc Estacion.cc Bici.cc Cjt_estacions.hh Cjt_bicis.hh Estacion.hh Bici.hh JDOPRO2ArnauHernández12.pdf html.zip makefile

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.tar