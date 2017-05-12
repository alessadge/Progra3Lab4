#include <iostream>

void juego();
bool revisarJuego(char**,int, int);
void printMatriz(int, char**);
void freeMatriz(int, char**);


int main(){
   char** pieza_matriz=new char*[8];
   for(int i=0;i<8;i++){
      pieza_matriz[i] = new char[8];
   }
   juego(pieza_matriz);


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

bool revisarJuego(char** pieza_matriz, int x, int y){
for(i=o;i<pieza_matriz

return false;
}

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
