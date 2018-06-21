#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

//espacio entre los bordes de la ventana y nuestra cuadricula
#define espacio 10
//tamano de cada espacio de la cuadricula
#define tam 50
//dimensiones de la cuadricula
#define filas 8
#define columnas 8
int matriz[filas][columnas];
Scalar negro(0, 0, 0);
Scalar blanco(255, 255, 255);
//para indicar si se ha presionado dentro de la cuadricula
bool bandera = false;
//para indicar si se ha encontrado un jugador
bool juegoTermino = false;

int altoV = tam*columnas + espacio * 4;
int anchoV = tam * filas + espacio * 4
Mat ventana(altoV, anchoV, CV_8UC3, negro);

void dibujarMatriz() {
	//dibujar bordes horizontales
	for (int i = 0; i < filas + 1; i++)
	{
		Point inicio1(espacio, tam * i + espacio);
		Point fin1(tam*columnas + espacio, tam * i + espacio);
		line(ventana, inicio1, fin1, blanco);
	}
	//dibujar bordes verticales
	for (int i = 0; i < filas + 1; i++)
	{
		Point inicio2(tam * i + espacio, espacio);
		Point fin2(tam * i + espacio, tam*filas + espacio);
		line(ventana, inicio2, fin2, blanco);
	}
}

int main(int argc, char const *argv[])
{
	namedWindow("Ventana");
	//setMouseCallback("Ventana", onMouse);//

	dibujarMatriz();

	while (true)
	{
		imshow("Ventana", ventana);
		if (waitKey(10) == 27) break;
	}
	return 0;
	return 0;
}