// INCLUIR LIBERIA
#include<iostream>

using namespace std;
int main(){
	
	double numero;
	
	cout << "---- Ejercicio 4 ----" << endl;
	
	cout << "Ingresa un numero" << endl;
	cin >> numero;
	
	cout << "El numero ingresado es " << numero << endl;
	
	if( numero > 0 ){ 
		cout << "El numero en valor absoluto es " << numero << " ya que es un numero positivo" << endl;
	} else{
		cout << "El numero en valor absoluto es " << -1*numero << endl;
	}
	
	return 0;
}
