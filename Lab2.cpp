#inclue <iostream>
using namespace std;

int menu(){
	int retValue=0;
	while(retValue < 1 || retValue > 5){
		cout<<"      MENU"<<endl
			<<"1.- Ejercicio 1"<<endl
			<<"2.- Ejercicio 2"<<endl
			<<"3.- Ejercicio 3"<<endl
			<<"4.- Salir"<<endl
			
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
