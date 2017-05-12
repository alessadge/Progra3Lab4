Main:  Main.o Pieza.o General.o Marine.o
	g++ Main.o Pieza.o General.o Marine.o -lncurses -o Main

Main.o: Main.cpp Pieza.h General.h Marine.h
	g++ -c Main.cpp

Pieza.o: Pieza.cpp Pieza.h
	g++ -c Pieza.cpp

Marine.o: Marine.cpp Marine.h Pieza.h
	g++ -c Marine.cpp

General.o: General.cpp General.h Pieza.h
	g++ -c General.cpp

clean:
	rm -f *.o *.main
                                                                          
