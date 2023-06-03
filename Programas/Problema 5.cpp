// INCLUIR LIBERIA
#include<iostream>

using namespace std;
int main(){
	
	int numero1, numero2, numero3, numero4, numero5, max;
	
	cout << "---- Ejercicio 1 ----" << endl;
	
	cout << "Ingresa el primer numero" << endl;
	cin >> numero1;
	
	cout << "Ingresa el segundo numero" << endl;
	cin >> numero2;
	
	cout << "Ingresa el tercero numero" << endl;
	cin >> numero3;
	
	cout << "Ingresa el cuatro numero" << endl;
	cin >> numero4;
	
	cout << "Ingresa el cinco numero" << endl;
	cin >> numero5;
	
	if( numero1 >= numero2){
		max = numero1;
	} else{
		max = numero2;
	}
	
	if( max <= numero3){
		max = numero3;
	} else{
		max = max;
	}
	
	if( max <= numero4){
		max = numero4;
	} else{
		max = max;
	}
	
	if( max <= numero5){
		max = numero5;
	} else{
		max = max;
	}
	
	cout << "El numero maximo es " << max << endl;
	return 0;
}
