#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;


#define espacio 10
#define tam 50
#define filas 9
#define columnas 8
//butones 
#define filasB 1
#define columnasB 8
#define tamB 20
int s; 
int bottom[8];// es un arreglo que representa los puntos de la matriz.
int matriz[8][8];
Scalar negro(0, 0, 0);
Scalar blanco(255, 255, 255);
Scalar verde (0, 255, 0);
bool bandera = false;
bool zero = false;
bool gameOver = false;
bool turn = false; 

int alto = tam*columnas + espacio * 9;
int ancho = tam * filas + espacio * 2;
Mat ventana(alto, ancho, CV_8UC3, negro);


void llenar(){
    for(int a =0;a < 8; a++){        //llenar con 0 ambos arreglos 
        for(int b = 0; b<8; b++)  
            matriz[a][b] = 0;} 
    for (int i=0; i<9;i++){
    	bottom[i]=7	;
    	cout<<bottom[i];
    }
}

int main(int argc, char const *argv[])
{
	llenar();
	return 0;
}