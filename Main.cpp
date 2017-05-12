#include <iostream>
#include <string>
#include <vector>
#include "Pieza.h"
#include "General.h"
#include "Marine.h"

using namespace std;


void juego();
bool revisarJuego(char**,int, int);
void printMatriz(int, char**);
void freeMatriz(int, char**);
void rellenarMatriz(int, char**);
void validaciones(int, char**,int, int);

int main(){


	initscr();
	start_color();

	attron(  A_BOLD);// de la libreria ncurses... para que todo sea en negrita


	echo();
	boardPic();


	//---------- ncurses

   char** pieza_matriz=new char*[8];
   for(int i=0;i<8;i++){
      pieza_matriz[i] = new char[8];
   }
   rellenarMatriz(8, pieza_matriz);
   juego(pieza_matriz);
   freeMatriz(8,pieza_matriz); 

return 0;
}

void juego(char** matrix){
   int x,y;
   bool gameOver=false,jugador=true;
   while(!gameOver){
      while(jugador){
	 printMatriz(8, matrix); 
	 cout<<"Turno de jugador 1: "<<endl<<
	 "Ingrese coordenada en X: "<<endl;
	 cin<<x;
	 cout<<"Ingrese coordenada en Y: "<<endl;
	 cin<<y;
	 
	 printMatriz(8, matrix);
	 jugador=false;
      }//turno jugador1
      
      while(!jugador){
	 printMatriz(8, matrix);
	 cout<<"Turno de jugador 2: "<<endl<<
	 "Ingrese coordenada en X: "<<endl;
	 cin<<x;
	 cout<<"Ingrese coordenada en Y:"<<endl;
	 cin<<y;

	 printMatriz(8, matrix);
	 jugador=true;
      }//turno de jugador2



   }//fin while
}//fin metodo juego

/*
bool revisarJuego(char** pieza_matriz, int x, int y){
for(i=o;i<pieza_matriz

return false;
}*/

void printMatriz(int size, char** matrix){
   size = 8;
   for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
	 cout<<" "<<matrix[i][j];
      }
      cout<<endl;
   }
}

void freeMatriz(int n, char** matrix){
   for(int i = 0; i < n; i++){
      delete[] matrix[i];
   }
   delete[] matrix;
}

void rellenarMatriz(int size, char** matrix){
   for(int i = 0; i < size; i ++){   
      for(int j = 0; j < size; j++){
       	// if(clase.getTipo() == 1){
	 if(i==0&&j==1||j==3||j==5||j==7){
	    matrix[i][j] = "|b|";
	 }//fin matriz primera fila
	 if(i==1&&j==0||j==2||j==4||j==6){
	    matrix[i][j] = "|b|";
	  }//fin matriz segunda fila
	 if(i==2&&j==1||j==3||j==5||j==7){
	    matrix[i][j] = "|b|";
	 }//fin matriz tercera fila
      //fin blancos if(clase.getTipo()== 2){
	 if(i==5&&j==0||j==2||j==4||j==6){
	    matrix[i][j] = "|n|";
	 }
	 if(i==6&&j==1||j==3||j==5||j==7){
	    matrix[i][j] = "|n|";
	 }
	 if(i==7&&j==0||j==2||j==4||j==6){
	    matrix[i][j] = "|n|";
	 }else{
	    matrix[i][j] = "| |";
      }
      //fin negro
      }
   }
}

void validaciones(int size, char** matrix, int x, int y){
   size=8;
   for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){   


      }
   }
}

