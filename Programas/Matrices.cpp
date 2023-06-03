#include<iostream>

using namespace std;
int main(){
	
	int CONTINUAR;
	
	do{
		
		int n, m, r, k;
		
		cout << "¿Deseas imprimir una matriz cuadrada o regular? (Cuadrada = 0; Regular = 1)" << endl;
			cin >> k;
		
		if( k == 1){
					
		cout << "¿Cuantas filas quieres que tenga la matriz?" << endl;
			cin >> n;
			
		cout << "¿Cuantas columnas quieres que tenga la matriz?" << endl;
			cin >> m;
	
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
			
				if(j == 1)
					cout << "( 0";
				else if( j == m )
					cout << " 0 )" << endl;
				else
					cout << " 0";	
						
			}
		}}
		else if( k == 0){
		cout << "¿De que dimension quieres que sea la matriz identidad?" << endl;
			cin >> r;
	
		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= r; j++){
			
				if(j == 1 && i == 1)
					cout << "( 1";
				else if(j == 1 && i != 1)
					cout << "( 0";
				else if ( j == i && j != r)
					cout << " 1";	
				else if( j == r && j != i)
					cout << " 0 )" << endl;
				else if( j == r && j == r)
					cout << " 1 )" << endl;
				else
					cout << " 0";	
						
			}
		}}		
	
	cout << "Deseas continuar (1: SI, 0: NO) " << endl;
		cin >> CONTINUAR;	
			
	}while( CONTINUAR == 1 );
	
	
	
	return 0;
}
	



