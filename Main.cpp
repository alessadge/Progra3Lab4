#include <iostream>
#include <string>
#include <vector>
#include "Pieza.h"
#include "General.h"
#include "Marine.h"
#include <ncurses.h>

using namespace std;


void juego(string**);
bool revisarJuego(string**,int, int);
void printMatriz(int, string**);
void freeMatriz(int, string**);
void rellenarMatriz(int, string**);
void validaciones(int, string**,int, int,int,int,int,int,int);

void boardPic();
void cleanScreen();

int main(){

   
	//initscr();
	//start_color();

	//attron(  A_BOLD);// de la libreria ncurses... para que todo sea en negrita


	//echo();
	//boardPic();


	//---------- ncurses


   string** pieza_matriz=new string*[8];

   for(int i=0;i<8;i++){
      pieza_matriz[i] = new string[8];
   }
   rellenarMatriz(8, pieza_matriz);
   juego(pieza_matriz);
   freeMatriz(8,pieza_matriz); 

return 0;
}

void juego(string** matrix){
   int x,y,posicionX,posicionY, tipo,cont1=0,cont2=0;
   bool gameOver=false,jugador=true;
   while(!gameOver){
      while(jugador==true){
	 printMatriz(8, matrix); 
	 cout<<endl<<"Turno de jugador 1:\n "<<
	 "Ingrese coordenada en X: "<<endl;
	 cin>>x;
	 cout<<"Ingrese coordenada en Y: "<<endl;
	 cin>>y;
	 cout<<"Posicion X para moverse: "<<endl;
	 cin>>posicionX;
	 cout<<"Posicion Y para moverse: "<<endl;
	 cin>>posicionY;
	 if(posicionX>7||posicionX<0||posicionY>7||posicionY<0){
            cout<<"Se salio de las casillas. "<<endl;
         }else{
	 validaciones(8,matrix,x,y,posicionX,posicionY,1,cont1,cont2);
	 if(cont1==12){
	    cout<<"GAME OVER. Gano Jugador 1";
	    gameOver=true;
	 }
	 jugador=false;
	 }
      }//turno jugador1
      
      while(!jugador){
	 cout<<endl;
	 printMatriz(8, matrix);
	 cout<<endl<<"Turno de jugador 2:\n Ingrese coordenada en X: "<<endl;
	 cin>>x;
	 cout<<"Ingrese coordenada en Y:"<<endl;
	 cin>>y;
	 cout<<"Posicion X para moverse: "<<endl;
         cin>>posicionX;
         cout<<"Posicion Y para moverse: "<<endl;
         cin>>posicionY;
	 if(posicionX>7||posicionX<0||posicionY>7||posicionY<0){
	    cout<<"Se salio de las casillas. "<<endl;
	 }else{
	 validaciones(8,matrix,x,y,posicionX,posicionY,2,cont1,cont2);
	 if(cont2==12){
	    cout<<"GAME OVER. Gano Jugador 2.";
	    gameOver=true;
	 }
	 jugador=true;
	 }
      }//turno de jugador2



   }//fin while
}//fin metodo juego

/*
bool revisarJuego(char** pieza_matriz, int x, int y){
for(i=o;i<pieza_matriz

return false;
}*/

void printMatriz(int size, string** matrix){
   //size = 8;
   for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
	 cout<< matrix[i][j];
      }
	cout<<endl;
   }
}

void freeMatriz(int n, string** matrix){
   for(int i = 0; i < n; i++){
      delete[] matrix[i];
   }
   delete[] matrix;
}

void rellenarMatriz(int size, string** matrix){
for(int i = 0 ; i < size; i++){
  for(int j = 0; j < size;j++){
      matrix[i][j]="| |";
		
  }
}
for(int i=0;i<size;i++){
  for(int j=0; j<size;j++){
    if(i==0&&j%2==1||i==2&&j%2==1){
      matrix[i][j]="|b|";
 }
    if(i==1&&j%2==0){
      matrix[i][j] = "|b|";
 }  
    if(i==6&&j%2==1){
      matrix[i][j]="|n|";
 }
    if(i==5&&j%2==0||i==7&&j%2==0){
      matrix[i][j] = "|n|";
 }

  }
 }
} 



void validaciones(int size, string** matrix, int x, int y, int posicionX,int posicionY,int tipo,int cont1,int cont2){
   size=8;
   string pos;
   pos = matrix[x][y];
      
   for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
	 matrix[x][y]="| |";   
	 if(tipo==1){
	    if(matrix[posicionX][posicionY]=="|n|")
	       cont1++;
	    if((posicionX==x+1&&posicionY==y-1)||(posicionX==x+1&&posicionY==y+1)){
	       if(posicionX==7){
		  matrix[posicionX][posicionY]="|B|";
	       }else{
	       matrix[posicionX][posicionY]="|b|";
	       }
	     }else{
	       matrix[x][y]="|b|";
	    }
	 }else{
	    if(matrix[posicionX][posicionY]=="|b|")
               cont2++;
	  
	    if(posicionX==x-1&&posicionY==y-1||posicionX==x-1&&posicionY==y+1){
	       if(posicionX==0){
		  matrix[posicionX][posicionY]="|N|";
	       }else{
	          matrix[posicionX][posicionY]="|n|";
	       }
	 	 
      }else{
	 matrix[x][y]="|n|";
      }
    }
  }
}
}

void boardPic(){
	move(1,1);
}


void cleanScreen(){
	for (int i = 0; i < LINES; i++){
		for (int j = 0; j < COLS; j++){
			mvprintw(i,j," ");
		}
	}
}



