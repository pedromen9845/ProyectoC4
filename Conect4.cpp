#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <fstream>
	
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

string J1nombre,J2nombre,J1alias,J2alias;
char temp;
int m=1, dat=4;
void x0(int, int, int);
int tablero[8][8];
Scalar negro(0, 0, 0);
Scalar blanco(255, 255, 255);
Scalar verde (0, 255, 0);
Scalar rojo (0,0,255);
bool bandera = false;
bool endgame = false;
void check();
void DibujarJuego();
void datos();
bool turn = false; 

int alto = tam*columnas + espacio * 8.5;
int ancho = tam *filas + espacio -2 ;
Mat ventana(alto, ancho, CV_8UC3, negro);
Mat Ins(400,400, CV_8UC3, negro);

//CODIGO DE AQUÍ EN ADELANTE ES ACERCA DEL JUEGO CONECT4 
void llenar(){
    for(int a =0;a < 8; a++){        //llenar con 0 ambos arreglos 
        for(int b = 0; b<8; b++)  
            tablero[a][b] = 0;}  
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

void dibujartablero() {

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
        for(int b =0; b <= 7; b++) cout<<tablero[a][b]<<" ";
        cout<<'\n';   
	}}

void dibujarMaru(int x, int y){
	Point centro(x + tam / 2, y + tam / 2);
	int radio = tam / 2 - espacio;
	circle(ventana, centro, radio, (turn? verde:blanco)); }

void kakuempate(){
	Mat Empate(200, 500, CV_8UC3, blanco);
    putText(Empate, "-Empate-", Point(5, 100), FONT_HERSHEY_SIMPLEX, 3, verde);
    imshow("Empate", Empate);

    endgame = true;
}

void ganador(){

}
void Empate(){
	int lleno=0;
	for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            if (tablero[i][j] != 0) lleno++;
if ( !endgame && lleno==64)kakuempate();

}


void onMouse(int event, int x, int y, int, void*) {
	if (endgame) return;
	if(m==0){
		if (event == EVENT_LBUTTONUP) {
			for (int i = 0; i < filas; i++)
			{
				int valor = tam*i + espacio;
				if (x >= valor && x < valor + tam && y >= espacio && y <=tam + espacio) {
				int s=7;
				x = tam * ((x - espacio) / tam) + espacio;
                y = tam * ((y - espacio) / tam) + espacio;
				while (s>=0){
	 				if (tablero[s][i]==0){
	 					tablero[s][i]=(turn? 1:2);
	 					dibujarMaru(x,y);
	 					turn=!turn;
	 					break;
	 						}
	 				else if (tablero[s][i]!=0){
	 					s--;
	 						}
	 						}
				bandera = true;
			}
		}
		//ganador();
		Empate();
		//check();


		if (bandera) {
			arr();
			bandera = false;
			//cout<<m<<endl;
		}
	}}
	//Para el menu
	else if (m==1){
		if (event==EVENT_LBUTTONUP){
			
				if (x >= 75 && x < 314 && y >= 62 && y <=135) {
					m=2;
					datos();

				}
				else if(x>=75 && x< 314 && y>=155 && y <=230){
					m=0;
					DibujarJuego(); 
					//Aquí irá la pantalla de puntuaciones, todavía no está hecha!
				}
		}
//sit
	}
	//Para ingreso de Datos
	else if (m==2){
		if (event==EVENT_LBUTTONUP){
			if(x>=110 && x<383 && y>=65 && y<=95){
				cout<<"cuadro de nombre"<<endl;
				
				if (waitKey()){
					while (true){
						if(J1nombre.length()==5 or waitKey()==13)break;

							temp=waitKey();
							J1nombre+=temp;
							putText(Ins,"-"+J1nombre,Point(115,90), FONT_HERSHEY_SIMPLEX,1,rojo);
							cout<<J1nombre<<endl;
					}}}
			else if (x>=110 && x<383 && y>=125 && y<=155)	{
				cout<<"cuadro de alias"<<endl;
				
					if (waitKey()){
						while (true){
							if(J1alias.length()==5 or waitKey()==13)break;

							temp=waitKey();
							J1alias+=temp;
							putText(Ins,"-"+J1alias,Point(115,150), FONT_HERSHEY_SIMPLEX,1,rojo);
							cout<<J1alias<<endl;

				}
				}		
							}
			else if(x>=110 && x<383 && y>=245 && y<=275){
				cout<<"cuadro de nombre"<<endl;
				
				if (waitKey()){
					while (true){
						if(J2nombre.length()==5 or waitKey()==13)break;

							temp=waitKey();
							J2nombre+=temp;
							putText(Ins,"-"+J2nombre,Point(115,270), FONT_HERSHEY_SIMPLEX,1,rojo);
							cout<<J2nombre<<endl;
					}}}	
			else if (x>=110 && x<383 && y>=305 && y<=335)	{
				cout<<"cuadro de alias"<<endl;
				
					if (waitKey()){
						while (true){
							if(J2alias.length()==5 or waitKey()==13)break;

							temp=waitKey();
							J2alias+=temp;
							putText(Ins,"-"+J2alias,Point(115,330), FONT_HERSHEY_SIMPLEX,1,rojo);
							cout<<J1alias<<endl;

				}
				}	
				}
			else if (x>=120 && x<=355 && y>=355 && y<=390 && J1nombre.length()!=0 && J2nombre.length()!=0 && J1alias.length()!=0 && J2alias.length()!=0 )	{
				m=0;
				DibujarJuego();
			}

}}}



//CODIGO DE AQÚI EN ADELANTE ES SOBRE EL MENU!!!!!
void dibujarBmenu(Mat Menu){
	putText(Menu, "-Conect 4-", Point(10,50), FONT_HERSHEY_SCRIPT_SIMPLEX, 2, verde);
    //imshow("Empate", Menu);
	
	Rect recPlay (75,63,240,73); 
		rectangle(Menu, recPlay,rojo, CV_FILLED);
		putText(Menu,"Jugar!",Point(105,115), FONT_HERSHEY_SIMPLEX,2,blanco);
	Rect recScore (75,158,240,73);
		rectangle(Menu, recScore,rojo,CV_FILLED); 
		putText(Menu,"Puntuacion",Point(81,210), FONT_HERSHEY_SIMPLEX,1.3,blanco);
}



void Menu(){
	Mat Menu (400,400,CV_8UC3,negro);
	namedWindow("Ventana");
	int option=0;
	dibujarBmenu(Menu);
	setMouseCallback("Ventana", onMouse);


	while (m==1)
	{
		imshow("Ventana", Menu);
		if (waitKey(5) == 27) 
			break;
		
	}
}
//A PARTIR DE ACÁ SE USARÁ CODIGO DE EL SISTEMA DE INSCRIPCIÓN
void Dibujarinscrip(Mat Ins){
	putText(Ins,"Jugador 1", Point(10,30), FONT_HERSHEY_SIMPLEX,0.7,blanco);
	
	putText(Ins,"Nombre: ", Point(10,85), FONT_HERSHEY_SIMPLEX,0.7,blanco);
		Rect recNamae1 (110,65,275,30); 
		rectangle(Ins, recNamae1,blanco,CV_FILLED);
	putText(Ins,"Alias: ", Point(10,145), FONT_HERSHEY_SIMPLEX,0.7,blanco);
		Rect recAlias1 (110,125,275,30);
		rectangle(Ins,recAlias1,blanco,CV_FILLED);

	putText(Ins,"Jugador 2", Point(10,210), FONT_HERSHEY_SIMPLEX,0.7,blanco);
	
	putText(Ins,"Nombre: ", Point(10,265), FONT_HERSHEY_SIMPLEX,0.7,blanco);
		Rect recNamae2 (110,245,275,30); 
		rectangle(Ins, recNamae2,blanco,CV_FILLED);
	putText(Ins,"Alias: ", Point(10,325), FONT_HERSHEY_SIMPLEX,0.7,blanco);
		Rect recAlias2 (110,305,275,30);
		rectangle(Ins,recAlias2,blanco,CV_FILLED);

		Rect Juego(120,355,155,35);
		rectangle(Ins,Juego,rojo,CV_FILLED);
	putText(Ins, "Iniciar Juego!",Point(125,380), FONT_HERSHEY_SIMPLEX, 0.7, verde);
		

}




int main(int argc, char const *argv[]) {
	
	Menu();
	//DibujarJuego();

	
}



 void check (){
  //filas
 for (int i=0; i<=7; i++){
	for (int j=0; j<=7;j++){
			
			if(tablero[i][j]==tablero[i][j+1] && tablero[i][j+2]==tablero[i][j+3] && tablero[i][j] == tablero[i][j+3] && tablero[i][j] !=0) {
			kakuempate();
			!endgame;}
	}
}
 //columnas
 for (int i=0; i<=7; i++){
	for (int j=0; j<=7;j++){
			
			if(tablero[i][j]==tablero[i+1][j] && tablero[i+2][j]==tablero[i+3][j] && tablero[i][j] == tablero[i+3][j] && tablero[i][j] !=0) {
			kakuempate();
			!endgame;}
	}
}
//diagonales izquierda a derecha
if(tablero[0][4]==tablero[1][5] && tablero[2][6]==tablero[3][7] && tablero[0][4] == tablero[3][7] && tablero[0][4] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[0][3]==tablero[1][4] && tablero[2][5]==tablero[3][6] && tablero[0][3] == tablero[3][6] && tablero[0][3] !=0){
			kakuempate();
			!endgame;}   
 
else if(tablero[1][4]==tablero[2][5] && tablero[3][6]==tablero[4][7] && tablero[1][4] == tablero[4][7] && tablero[1][4] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[0][2]==tablero[1][3] && tablero[2][4]==tablero[3][5] && tablero[0][2] == tablero[3][5] && tablero[0][2] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[1][3]==tablero[2][4] && tablero[3][5]==tablero[4][6] && tablero[1][3] == tablero[4][6] && tablero[1][3] !=0){
			kakuempate();
			!endgame;}   

else if(tablero[2][4]==tablero[3][5] && tablero[4][6]==tablero[5][7] && tablero[2][4] == tablero[5][7] && tablero[2][4] !=0){
			kakuempate();
			!endgame;}

else if(tablero[0][1]==tablero[1][2] && tablero[2][3]==tablero[3][4] && tablero[0][1] == tablero[3][4] && tablero[0][1] !=0){
			kakuempate();
			!endgame;} 

else if(tablero[1][2]==tablero[2][3] && tablero[3][4]==tablero[4][5] && tablero[1][2] == tablero[4][5] && tablero[1][2] !=0){
			kakuempate();
			!endgame;}  

else if(tablero[2][3]==tablero[3][4] && tablero[4][5]==tablero[5][6] && tablero[2][3] == tablero[5][6] && tablero[2][3] !=0){
			kakuempate();
			!endgame;} 
 
else if(tablero[3][4]==tablero[4][5] && tablero[5][6]==tablero[6][7] && tablero[3][4] == tablero[6][7] && tablero[3][4] !=0) {
			kakuempate();
			!endgame;}
    
else if(tablero[0][0]==tablero[1][1] && tablero[2][2]==tablero[3][3] && tablero[0][0] == tablero[3][3] && tablero[0][0] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[1][1]==tablero[2][2] && tablero[3][3]==tablero[4][4] && tablero[1][1] == tablero[4][4] && tablero[1][1] !=0){
			kakuempate();
			!endgame;}   
 
else if(tablero[2][2]==tablero[3][3] && tablero[4][4]==tablero[5][5] && tablero[2][2] == tablero[5][5] && tablero[2][2] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[3][3]==tablero[4][4] && tablero[5][5]==tablero[6][6] && tablero[3][3] == tablero[6][6] && tablero[3][3] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[4][4]==tablero[5][5] && tablero[6][6]==tablero[7][7] && tablero[4][4] == tablero[7][7] && tablero[4][4] !=0){
			kakuempate();
			!endgame;}   

else if(tablero[2][4]==tablero[3][5] && tablero[4][6]==tablero[5][7] && tablero[2][4] == tablero[5][7] && tablero[2][4] !=0){
			kakuempate();
			!endgame;}

else if(tablero[0][1]==tablero[1][2] && tablero[2][3]==tablero[3][4] && tablero[0][1] == tablero[3][4] && tablero[0][1] !=0){
			kakuempate();
			!endgame;} 

else if(tablero[1][0]==tablero[2][1] && tablero[3][2]==tablero[4][3] && tablero[1][0] == tablero[4][3] && tablero[1][0] !=0){
			kakuempate();
			!endgame;}

else if(tablero[2][1]==tablero[3][2] && tablero[4][3]==tablero[5][4] && tablero[2][1] == tablero[5][4] && tablero[2][1] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[3][2]==tablero[4][3] && tablero[5][4]==tablero[6][5] && tablero[3][2] == tablero[6][5] && tablero[3][2] !=0){
			kakuempate();
			!endgame;}   
 
else if(tablero[4][3]==tablero[5][4] && tablero[6][5]==tablero[7][6] && tablero[4][3] == tablero[7][6] && tablero[4][3] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[2][0]==tablero[3][1] && tablero[4][2]==tablero[5][3] && tablero[2][0] == tablero[5][3] && tablero[2][0] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[3][1]==tablero[4][2] && tablero[5][3]==tablero[6][4] && tablero[3][1] == tablero[6][4] && tablero[3][1] !=0){
			kakuempate();
			!endgame;}   

else if(tablero[4][2]==tablero[5][3] && tablero[6][4]==tablero[7][5] && tablero[4][2] == tablero[7][5] && tablero[4][2] !=0){
			kakuempate();
			!endgame;}

else if(tablero[3][0]==tablero[4][1] && tablero[5][2]==tablero[6][3] && tablero[3][0] == tablero[6][3] && tablero[3][0] !=0){
			kakuempate();
			!endgame;} 

else if(tablero[4][1]==tablero[5][2] && tablero[6][3]==tablero[7][4] && tablero[4][1] == tablero[7][4] && tablero[4][1] !=0){
			kakuempate();
			!endgame;}  

else if(tablero[4][0]==tablero[5][1] && tablero[6][2]==tablero[7][3] && tablero[4][0] == tablero[7][3] && tablero[4][0] !=0){
			kakuempate();
			!endgame;} 

//diagonales de derecha a izquierda
 
else if(tablero[7][4]==tablero[6][5] && tablero[5][6]==tablero[4][7] && tablero[7][4] == tablero[4][7] && tablero[7][4] !=0) {
			kakuempate();
			!endgame;}
    
else if(tablero[7][3]==tablero[6][4] && tablero[5][5]==tablero[4][6] && tablero[7][3] == tablero[4][6] && tablero[7][3] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[6][4]==tablero[5][5] && tablero[4][6]==tablero[3][7] && tablero[6][4] == tablero[3][7] && tablero[6][4] !=0){
			kakuempate();
			!endgame;}   
 
else if(tablero[7][2]==tablero[6][3] && tablero[5][4]==tablero[4][5] && tablero[7][2] == tablero[4][5] && tablero[7][2] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[6][3]==tablero[5][4] && tablero[4][5]==tablero[3][6] && tablero[6][3] == tablero[3][6] && tablero[6][3] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[5][4]==tablero[4][5] && tablero[3][6]==tablero[1][7] && tablero[5][4] == tablero[2][7] && tablero[4][4] !=0){
			kakuempate();
			!endgame;}   

else if(tablero[7][1]==tablero[6][2] && tablero[5][3]==tablero[4][4] && tablero[7][1] == tablero[4][4] && tablero[7][1] !=0){
			kakuempate();
			!endgame;}

else if(tablero[6][2]==tablero[5][3] && tablero[4][4]==tablero[3][5] && tablero[6][2] == tablero[3][5] && tablero[6][2] !=0){
			kakuempate();
			!endgame;} 

else if(tablero[5][3]==tablero[4][4] && tablero[3][5]==tablero[2][6] && tablero[5][3] == tablero[2][6] && tablero[5][3] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[4][4]==tablero[3][5] && tablero[2][6]==tablero[1][7] && tablero[4][4] == tablero[1][7] && tablero[4][4] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[7][0]==tablero[6][1] && tablero[5][2]==tablero[4][3] && tablero[7][0] == tablero[4][3] && tablero[7][0] !=0) {
			kakuempate();
			!endgame;}
    
else if(tablero[6][1]==tablero[5][2] && tablero[4][3]==tablero[3][4] && tablero[6][1] == tablero[5][2] && tablero[6][1] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[5][2]==tablero[4][3] && tablero[3][4]==tablero[2][5] && tablero[5][2] == tablero[2][5] && tablero[5][2] !=0){
			kakuempate();
			!endgame;}   
 
else if(tablero[4][3]==tablero[3][4] && tablero[2][5]==tablero[1][6] && tablero[4][3] == tablero[1][6] && tablero[4][3] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[3][4]==tablero[2][5] && tablero[1][6]==tablero[0][7] && tablero[3][4] == tablero[0][7] && tablero[3][4] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[6][0]==tablero[5][1] && tablero[4][2]==tablero[3][3] && tablero[6][0] == tablero[3][3] && tablero[6][0] !=0){
			kakuempate();
			!endgame;}   

else if(tablero[5][1]==tablero[4][2] && tablero[3][3]==tablero[2][4] && tablero[5][1] == tablero[2][4] && tablero[5][1] !=0){
			kakuempate();
			!endgame;}

else if(tablero[4][2]==tablero[3][3] && tablero[2][4]==tablero[1][5] && tablero[4][2] == tablero[1][5] && tablero[4][2] !=0){
			kakuempate();
			!endgame;} 

else if(tablero[3][3]==tablero[2][4] && tablero[1][5]==tablero[0][6] && tablero[3][3] == tablero[0][6] && tablero[3][3] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[5][0]==tablero[4][1] && tablero[3][2]==tablero[2][3] && tablero[5][0] == tablero[2][3] && tablero[5][0] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[4][1]==tablero[3][2] && tablero[2][3]==tablero[1][4] && tablero[4][1] == tablero[1][4] && tablero[4][1] !=0) {
			kakuempate();
			!endgame;}
    
else if(tablero[3][2]==tablero[2][3] && tablero[1][4]==tablero[0][5] && tablero[3][2] == tablero[0][5] && tablero[3][2] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[4][0]==tablero[3][1] && tablero[2][2]==tablero[1][3] && tablero[4][0] == tablero[1][3] && tablero[4][0] !=0){
			kakuempate();
			!endgame;}   
 
else if(tablero[3][1]==tablero[2][2] && tablero[1][3]==tablero[0][4] && tablero[3][1] == tablero[0][4] && tablero[3][1] !=0){
			kakuempate();
			!endgame;}
 
else if(tablero[3][0]==tablero[2][1] && tablero[1][2]==tablero[0][3] && tablero[3][0] == tablero[0][3] && tablero[3][0] !=0){
			kakuempate();
			!endgame;}
 
 
 
 
 //check final
 }

    

void datos(){
	
	namedWindow("Ventana");
	Dibujarinscrip(Ins);

	while(true){
		imshow("Ventana",Ins);
			if(waitKey(5)==27) 
			break;
	}

}
void DibujarJuego(){
	namedWindow("Ventana");

	setMouseCallback("Ventana", onMouse);
	arr();
	dibujartablero();
	dibujarButtons();

	while (true)
	{
		imshow("Ventana", ventana);
		if (waitKey(10) == 27) {break;
		break;}
		
	}

}
