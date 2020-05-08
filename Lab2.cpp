#include <iostream>
using namespace std;

int menu(){
	int retValue=0;
	while(retValue < 1 || retValue > 5){
		cout<<"      MENU"<<endl
			<<"1.- Ejercicio 1"<<endl
			<<"2.- Ejercicio 2"<<endl
			<<"3.- Ejercicio 3"<<endl
			<<"4.- Salir"<<endl;
			
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

int main(){
	int  opcion = menu();
	
	switch(opcion){
		case 1:{
			
			break;
		}
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
			break;
		}
		case 3:{
			
			break;
		}
		case 4:{
			cout<<endl<<"Gracias por entrar al sistema."<<endl;
			break;
		}
	}//fin del switch
}
