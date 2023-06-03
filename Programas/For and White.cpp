// INCLUIR LIBERIA
#include<iostream>

using namespace std;
int main(){
	
	int CONTINUAR;
	
	do{
		
		int n, N;
		double max, pro, min, par;
	
		max = -999999;
		min = 9999999;
		N = 0;
	
		for(int i = 1; i <= 10; i++){
			cout << "Ingresa un numero entero" << endl;
			cin >> n;
			
			pro += n;
			N += 1;
			
			if(n > max){
				max = n;
			}
		
			if(n < min){
				min = n;
			}
		
			if(n%2 == 0){
				par += 1;
			}
		}
	
	cout << "El valor maximo es " << max << endl;
	cout << "El valor minimo es " << min << endl;
	cout << "El promedio es " << pro/N << endl;
	cout << "La cantidad de numeros pares es " << par << endl;
	
	cout << "Deseas continuar (1: SI, 0: NO) " << endl;
	cin >> CONTINUAR;
	
	}while( CONTINUAR == 1 );

	
	return 0;
}
