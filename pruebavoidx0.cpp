#include <iostream>
using namespace std;
int matriz[8][8];
bool turn=false;

void arr() {
	cout<<"1 2 3 4 5 6 7 8\n";
    for(int a = 0; a<= 7; a++)
    {
        for(int b =0; b <= 7; b++) cout<<matriz[a][b]<<" ";
        cout<<'\n';   
	}}


int main(int argc, char const *argv[])
{
	int i;
	for (int o=0; o<8; o++){
	cout<<"inserte un numero: "<<endl;
	cin >>i;
	 int s=7;
	 while (s>=0){
	 	if (matriz[s][i]==0){
	 		matriz[s][i]=(turn? 1:2);
	 		arr();
	 		turn=!turn;
	 		break;
	 	}
	 	else if (matriz[s][i]!=0){
	 		s--;
	 	}
	 }
	 arr();
	}
	
	

	return 0;
}