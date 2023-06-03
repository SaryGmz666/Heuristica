// INCLUIR LIBERIA
#include<iostream>

using namespace std;
int main(){
	
	int numero;
	
	cout << "---- ¿El numero ingresado es PAR o IMPAR? ----" << endl;
	
	cout << "Ingresa un numero entero" << endl;
	cin >> numero; 
	
	if( numero%2 == 0){ // El % significa modulo (numero MOD(2)
		cout << "El numero " << numero << " es par" << endl;
	} else{
		cout << "El numero " << numero << " es impar" << endl;
	}
	
	return 0;
}
