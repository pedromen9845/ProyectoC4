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

int bottom[8];// es un arreglo que representa los puntos de la matriz.
int matriz[8][8];
Scalar negro(0, 0, 0);
Scalar blanco(255, 255, 255);
Scalar verde (0, 255, 0);
bool bandera = false;
bool gameOver = false;

int alto = tam*columnas + espacio * 9;
int ancho = tam * filas + espacio * 2;
Mat ventana(alto, ancho, CV_8UC3, negro);


void llenar(){
    for(int a =0;a <= 7; a++){        //llenar con 0
        for(int b = 0; b<=7; b++)  
            matriz[a][b] = 0;} 
    for (int i=0; i<9;i++){
    	bottom[i]=7;
    }   
}


void dibujarButtons(){
	//cuadros verdes en los cuales se trabajarán los botones, se deben hacer flechas verticales 
	//horizontales
	for (int i=0; i < filasB; i++) {
		Point inicioB(espacio, tam*i + espacio);
		Point finB(tam*columnasB+espacio, tam*i+espacio);
		line(ventana, inicioB, finB, verde);
	} // verticales
	for (int i = 0; i<9; i++){
			Point inicio2(tam*i + espacio, espacio);
		Point fin2(tam*i + espacio, tam*filasB + espacio);
		line(ventana, inicio2, fin2, verde);
	}
	}

void dibujarMatriz() {

	for (int i = 0; i < filas + 1; i++)	
	{
		Point inicio1(espacio, (tam*i + espacio));
		Point fin1(tam*columnas + espacio, tam*i + espacio);
		line(ventana, inicio1, fin1, blanco);
	}

	for (int i = 0; i < filas; i++)
	{
		Point inicio2(tam*i + espacio, espacio);
		Point fin2(tam*i + espacio, tam*filas + espacio);
		line(ventana, inicio2, fin2, blanco);
	}
	}

void arr() {
	cout<<"1 2 3 4 5 6 7 8\n";
    for(int a = 0; a<= 7; a++)
    {
        for(int b =0; b <= 7; b++) cout<<matriz[a][b]<<" ";
        cout<<'\n';   
	}}

void Onmouse(int event, int x, int y, int, void*) {
// onmouse solo funciona para detectar el click, todavía falta hacer bien el movimiento de la matriz
	if (event == EVENT_LBUTTONUP) 
	{	for (int i =0; i<8;i++)
		{
			for (int i = 0; i < filas; i++)
			{
			int valor = tam*i + espacio;
			if (x >= valor && x < valor + tam && y >= espacio && y <=tam + espacio) 
			{
				matriz[7][i]++;
		if (bandera) {
			arr();
			bandera = false;}

	}	}}
	}
}

void dibujarMaru(){



}


int main(int argc, char const *argv[]) {

	namedWindow("Ventana");

	setMouseCallback("Ventana", Onmouse);
	dibujarMatriz();
	dibujarButtons();
	

	while (true)
	{
		imshow("Ventana", ventana);
		if (waitKey(10) == 27) break;
		arr();
	}
	return 0;
}
