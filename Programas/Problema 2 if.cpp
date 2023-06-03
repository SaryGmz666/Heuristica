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
	
	if( numero1 <= numero2 && numero2 <= numero3 && numero3 <= numero4 && numero4 <= numero5){
		cout << "Los numeros ingresados estan ordenados de forma creciente " << endl;
	} else{
		cout << "Los numeros ingresados no estan ordenados de forma creciente " << endl;
	}
	
	return 0;
}
