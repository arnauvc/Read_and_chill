# MAKEFILE: utilidad para preparar ejecutables en los que intervienen
# varias clases, de forma que con una unica instruccion se compilan o linkan
# los ficheros estrictamente necesarios.
#

OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

all: Biblioteca.o Text.o Frase.o Taulesaux.o program.o program.exe clean practica.tar
	
Biblioteca.o: Biblioteca.cc Biblioteca.hh
	g++ -c $(OPCIONS) Biblioteca.cc 
 
Text.o: Text.cc Text.hh
	g++ -c $(OPCIONS) Text.cc 
 
Frase.o: Frase.cc Frase.hh
	g++ -c $(OPCIONS) Frase.cc 

Taulesaux.o: Taulesaux.cc Taulesaux.hh
	g++ -c $(OPCIONS) Taulesaux.cc 
 
program.o: program.cc
	g++ -c $(OPCIONS) program.cc 
 
program.exe: program.o Biblioteca.o Text.o Frase.o Taulesaux.o
	g++ -o  program.exe program.o Biblioteca.o Text.o Frase.o Taulesaux.o


	
practica.tar: Biblioteca.cc Biblioteca.hh Makefile program.cc Text.cc Text.hh Frase.cc Frase.hh Taulesaux.cc Taulesaux.hh
	tar -cvf practica.tar Biblioteca.cc Biblioteca.hh Makefile program.cc Frase.cc Frase.hh Text.cc Text.hh Taulesaux.cc Taulesaux.hh

clean:
	rm *.o
	
clean1:
	rm *.exe

