#!/bin/bash


all: bin/testimagen bin/testcodificar bin/prueba

bin/testimagen: obj/testimagen.o obj/imagen.o obj/pgm.o
	g++ obj/testimagen.o obj/imagen.o obj/pgm.o -o bin/testimagen

bin/testcodificar: obj/testcodificar.o obj/codificar.o obj/imagen.o obj/byte.o obj/pgm.o
	g++ obj/testcodificar.o obj/codificar.o obj/imagen.o obj/byte.o obj/pgm.o -o bin/testcodificar

bin/prueba: obj/imagen.o obj/codificar.o obj/prueba.o obj/byte.o obj/pgm.o
	g++ obj/prueba.o obj/imagen.o obj/codificar.o obj/byte.o obj/pgm.o -o bin/prueba

obj/prueba.o: src/prueba.cpp include/imagen.h include/codificar.h include/byte.h include/pgm.h
	g++ -c src/prueba.cpp  -I ./include -o obj/prueba.o

obj/codificar.o: src/codificar.cpp include/codificar.h include/byte.h include/imagen.h
	g++ -c src/codificar.cpp -I ./include -o obj/codificar.o

obj/testcodificar.o: src/testcodificar.cpp include/byte.h include/imagen.h include/codificar.h include/pgm.h
	g++ -c  src/testcodificar.cpp -I ./include -o obj/testcodificar.o

obj/byte.o: src/byte.cpp include/byte.h
	g++ -c src/byte.cpp -I ./include -o obj/byte.o

obj/testimagen.o: src/testimagen.cpp include/imagen.h 
	g++ -c src/testimagen.cpp -I ./include -o obj/testimagen.o

obj/imagen.o: src/imagen.cpp include/imagen.h include/pgm.h
	g++ -c src/imagen.cpp  -I ./include -o obj/imagen.o

obj/pgm.o: src/pgm.cpp include/pgm.h 
	g++ -c src/pgm.cpp -I ./include -o obj/pgm.o


mrproper:
	@echo "Borrando ejecutables..."
	rm bin/*
	@echo "Borrando los ficheros objetos"
	rm obj/*.o
