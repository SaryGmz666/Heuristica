// INCLUIR LIBERIA
#include<iostream>

using namespace std;

int main(){

int foo [] = { 16, 2, 77, 40, 12071};
int n, result = 0, sum = 0;


for( n = 0; n < 5; n++ ){
	result += foo [n];
}
	cout << result << endl;
	
	int lis [15];
	result = 0;
	
	for( int y = 0; y < 15; y++ ){
		cout << "Ingresa un numero" << endl;
		cin >> lis[y];
	}
	
	cout << "Los numeros que estan en posiciones pares son: ";
	for( int x= 0; x < 15; x += 2){
		if( x == 14 ){
			cout << lis[x] << endl;
		}else{
			cout << lis[x] << "\t";
		}
		
	}
	
	cout << "La suma de las posiciones impares es: ";
	for( int x= 1; x < 15; x += 2){
		sum += lis[x];
	}
	
	cout << sum << endl;
	
	return 0;
}


