// INCLUIR LIBERIA
#include<iostream>

using namespace std;
int main(){
	
	int numero1, numero2, numero3, max;
	
	cout << "---- Ejercicio 1 ----" << endl;
	
	cout << "Ingresa el primer numero" << endl;
	cin >> numero1;
	
	cout << "Ingresa el segundo numero" << endl;
	cin >> numero2;
	
	cout << "Ingresa el tercero numero" << endl;
	cin >> numero3;
	
	if( numero1 <= numero2){
		max = numero2;
	} else{
		max = numero1;
	}
	
	if( max <= numero3){
		cout << "El numero que no esta en los extremos es " << max << endl;
	} else{
		cout << "El numero que no esta en los extremos es " << numero3 << endl;
	}
	
	
	return 0;
}
