# MAKEFILE: utilidad para preparar ejecutables en los que intervienen
# varias clases, de forma que con una unica instruccion se compilan o linkan
# los ficheros estrictamente necesarios.
#

all: Biblioteca.o Text.o Frase.o program.o program.exe
	
Biblioteca.o: Biblioteca.cc Biblioteca.hh
	g++ -c Biblioteca.cc -D_GLIBCXX_DEBUG
 
Text.o: Text.cc Text.hh
	g++ -c Text.cc -D_GLIBCXX_DEBUG
 
Frase.o: Frase.cc Frase.hh
	g++ -c Frase.cc -D_GLIBCXX_DEBUG
 
program.o: program.cc
	g++ -c program.cc -D_GLIBCXX_DEBUG
 
program.exe: program.o Biblioteca.o Text.o Frase.o
	g++ -o program.exe program.o Biblioteca.o Text.o Frase.o


#	
# practica.tar: Biblioteca.cc Biblioteca.hh Makefile program.cc Text.cc Text.hh Frase.cc Frase.hh
# tar -cvf practica.tar Biblioteca.cc Biblioteca.hh Makefile program.cc Frase.cc Frase.hh	Text.cc Text.hh
#
clean:
	rm *.o
	rm *.exe
