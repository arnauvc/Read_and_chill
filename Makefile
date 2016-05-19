# MAKEFILE: utilidad para preparar ejecutables en los que intervienen
# varias clases, de forma que con una unica instruccion se compilan o linkan
# los ficheros estrictamente necesarios.
#

all: Biblioteca.o Text.o Frase.o Taulesaux.o program.o program.exe clean practica.tar
	
Biblioteca.o: Biblioteca.cc Biblioteca.hh
	g++ -c Biblioteca.cc -D_GLIBCXX_DEBUG
 
Text.o: Text.cc Text.hh
	g++ -c Text.cc -D_GLIBCXX_DEBUG
 
Frase.o: Frase.cc Frase.hh
	g++ -c Frase.cc -D_GLIBCXX_DEBUG

Taulesaux.o: Taulesaux.cc Taulesaux.hh
	g++ -c Taulesaux.cc -D_GLIBCXX_DEBUG
 
program.o: program.cc
	g++ -c program.cc -D_GLIBCXX_DEBUG
 
program.exe: program.o Biblioteca.o Text.o Frase.o Taulesaux.o
	g++ -o program.exe program.o Biblioteca.o Text.o Frase.o Taulesaux.o


	
practica.tar: Biblioteca.cc Biblioteca.hh Makefile program.cc Text.cc Text.hh Frase.cc Frase.hh Taulesaux.cc Taulesaux.hh
	tar -cvf practica.tar Biblioteca.cc Biblioteca.hh Makefile program.cc Frase.cc Frase.hh Text.cc Text.hh Taulesaux.cc Taulesaux.hh

clean:
	rm *.o
	
clean1:
	rm *.exe
