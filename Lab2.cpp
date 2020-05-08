#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int menu(){
	int retValue=0;
	while(retValue < 1 || retValue > 5){
		cout<<"      MENU"<<endl
			<<"1.- Ejercicio 1"<<endl
			<<"2.- Ejercicio 2"<<endl
			<<"3.- Ejercicio 3"<<endl
			<<"4.- Salir"<<endl
			<<"Que opcion desea ver: ";
			
			cin>>retValue;
			
			/*
			Llamar metodos para limpiar el buffer del "cin"
			*/
			
			if(retValue >= 1 && retValue <= 5){
				break;
			}else{
				cout<<endl<<"Opcion ingresada incorrecta, elija nuevamente"<<endl;
			}
			
			
	}//end while
	
	return retValue;
}

int MCD(int, int);
int main(){
	int  opcion = menu();
	int seguir = 1;
	
	while(seguir == 1){
		switch(opcion){
			case 1:{
				int n;
				cout<<"Ingrese el numero que quiere chequear el phi: ";
				cin>>n;
				while(n<1){
					cout<<endl<<"intentelo de nuevo, el numero debe ser mayor o igual a 0: ";
					cin>>n;
				}
			
				int contador=0;
				int mcd;
				for(int i = 1; i <= n; i++){
					mcd = MCD(n, i);
					if(mcd == 1){
						contador++;
					}
				}
			
				cout<<"El phi de el numero ingresado es: "<<contador<<endl;
				opcion = menu();
				break;
			}//fin case 1
			case 2:{
				int filas;
				cout<<endl<<"Cuantas filas quiere en el triangulo de pascal: ";
				cin>>filas;
				while(filas<1){
					cout<<endl<<"intentelo de nuevo, el numero debe ser mayor a 0: ";
					cin>>filas;
				}
				int pascal[filas][filas];
				for(int i = 0; i < filas; i++){
					if(i == 0){
						pascal[i][0]=1;	
					}else if(i == 1){
						pascal[i][0]=1;
						pascal[i][1]=1;
					}else{
						for(int j = 1; j < i; j++){
							pascal[i][i]= 1;
							pascal[i][0]= 1;
							pascal[i][j]= pascal[i-1][j] + pascal[i-1][j-1];
							
						}
					}
				}
				for(int i = 0; i < filas; i++){
					for(int j = 0; j < i+1; j++){
						cout<<pascal[i][j]<<", ";
					}
					cout<<""<<endl;
				}
				opcion = menu();
				break;
			}//fin case 2
			case 3:{
				int size;
				cout<<endl<<"De que tamaño quiere el arreglo, debe ser numero par: ";
				cin>>size;
				while(size<1 || size % 2 != 0){
					cout<<endl<<"intentelo de nuevo, el numero debe ser mayor a 0 y numero par: ";
					cin>>size;
				}
				
				int array[size];
				srand(time(NULL));
				
				for(int i = 0; i < size; i++){
					array[i] = (-50) + rand()%((51)-(-50));
				}
				
				int J1[size/2];
				int J2[size/2];
				int selected[size];
				for(int i = 0; i < size; i++){
					selected[i]= -1;
				}
				int cont;
				for(int i = 0; i < size/2; i++){//inicio del for del juego
					int numselected;
					cout<<"J1, escoga un numero: ";
					cin>>numselected;
					
					for(int j = 0; j < size; j++){
						if( numselected == selected[j] ){
							cout<<"J1 ese numero ya fue elegido, escoga otro numero: ";
							cin>>numselected;
							j=0;
						}
					}
					selected[cont] = numselected;
					cont++;
					cout<<"J1 obtuvo: "<<array[numselected]<<endl;
					J1[i] = array[numselected];
					
					
					cout<<"J2, escoga un numero: ";
					cin>>numselected;
					
					for(int j = 0; j < size; j++){
						if(numselected == selected[j]){
							cout<<"J2 ese numero ya fue elegido, escoga otro numero: ";
							cin>>numselected;
							j=0;
						}
					}
					selected[cont] = numselected;
					cont++;
					cout<<"J2 obtuvo: "<<array[numselected]<<endl;
					J2[i] = array[numselected];
					
					
					int sumJ1=0;
					int sumJ2=0;
					for(int j = 0; j <= i; j++){
						sumJ1 = sumJ1 + J1[j];
						sumJ2 = sumJ2 + J2[j];
					}
					
					if((i+1) == (size/2)){
						cout<<"Final "<<" -  PTS J1: "<<sumJ1<<"  <->  PTS J2: "<<sumJ2<<endl;
						if(sumJ1 > sumJ2){
							cout<<"GANO J1"<<endl;
						}else if(sumJ1 < sumJ2){
							cout<<"GANO J2"<<endl;
						}else if(sumJ1 == sumJ2){
							cout<<"EMPATE"<<endl;
						}
						
						cout<<"Arreglo usado: [";
						for(int j = 0; j < size; j++){
							cout<<array[j]<<", ";
						}
						cout<<"]"<<endl;
					
					}else{
						cout<<"Ronda "<<i+1<<" -  PTS J1: "<<sumJ1<<"  <->  PTS J2: "<<sumJ2<<endl;
					}
				}//fin for del juego
				opcion = menu();
				break;
			}//fin case 3
			case 4:{
				cout<<endl<<"Gracias por entrar al sistema."<<endl;
				seguir=0;
				break;
			}
		}//fin del switch
	}
	
}

int MCD (int n, int ii){//metodo para encontrar el multiplo comun divisor
	bool mcd_n=0;
	bool mcd_ii=0;
	int mcd=0;
	
	for(int i = 1; i < n+ii; i++){
		if(n % i == 0){
			mcd_n = true;
		}else{
			mcd_n = false;
		}
		
		if(ii % i == 0){
			mcd_ii = true;
		}else{
			mcd_ii = false;
		}
		
		if(mcd_n && mcd_ii ){
			mcd = i;
		}
	}
	return mcd;
}
