OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o ConsultaBool.o Coleccion.o Album.o Foto.o Fecha.o
	g++ -o program.exe program.o ConsultaBool.o Coleccion.o Album.o Foto.o Fecha.o
	rm *.o

program.o: program.cc ConsultaBool.hh Coleccion.hh Album.hh Foto.hh Fecha.hh
	g++ -c program.cc $(OPCIONS)

ConsultaBool.o: ConsultaBool.cc Coleccion.cc Coleccion.hh Album.hh Foto.hh Fecha.hh
	g++ -c ConsultaBool.cc $(OPCIONS)

Coleccion.o: Coleccion.cc Coleccion.hh Album.hh Foto.hh Fecha.hh
	g++ -c Coleccion.cc $(OPCIONS)

Album.o: Album.cc Album.hh Foto.hh Fecha.hh
	g++ -c Album.cc $(OPCIONS)


Foto.o: Foto.cc Foto.hh Fecha.hh
	g++ -c Foto.cc $(OPCIONS)

Fecha.o: Fecha.cc Fecha.hh
	g++ -c Fecha.cc $(OPCIONS)



practica.tar: program.cc ConsultaBool.cc ConsultaBool.hh Coleccion.cc Coleccion.hh Album.cc Album.hh Foto.cc Foto.hh Fecha.cc Fecha.hh Makefile
	tar -cvf practica.tar program.cc ConsultaBool.cc ConsultaBool.hh Coleccion.cc Coleccion.hh Album.cc Album.hh Foto.cc Foto.hh Fecha.cc Fecha.hh Makefile

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.tar

