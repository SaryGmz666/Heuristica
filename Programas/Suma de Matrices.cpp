#include<iostream>

using namespace std;
int main(){
	
	int CONTINUAR;
	
	do{
		
		int n, m, r;
		double dato;
		
	
					
		cout << "¿Cuantas filas tienen las matrices?" << endl;
			cin >> n;
			
		cout << "¿Cuantas columnas tienen las matrices?" << endl;
			cin >> m;
			
		int Mat1[n][m], Mat2[n][m];	
		
		cout << " " << endl;
		
		cout << "Ingresa los elementos de la primera matriz" << endl;
				
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
			
				cout << "Fila " << i+1 << "; Columna " << j+1 << endl;
					cin >> dato;	
				
				Mat1[i][j] = dato;		
			}
		}
	
		cout << " " << endl;
		
		cout << "La matricez ingresadas es: " << endl;
		
		for(int fila = 0; fila < n; fila++){
        	for(int col = 0; col < m; col ++){
            	
            	cout << Mat1[fila][col] << "\t";
        	}
        	cout << endl;
    	}
	
		cout << " " << endl;
		
		cout << "Ingresa los elementos de la segunda matriz" << endl;
				
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
			
				cout << "Fila " << i+1 << "; Columna " << j+1 << endl;
					cin >> dato;	
				
				Mat2[i][j] = dato;		
			}
		}
	
		cout << " " << endl;
		
		cout << "La matricez ingresadas es: " << endl;
		
		for(int fila = 0; fila < n; fila++){
        	for(int col = 0; col < m; col ++){
            	
            	cout << Mat2[fila][col] << "\t";
        	}
        	cout << endl;
    	}
	
		cout << " " << endl;
		
		cout << "La suma de las matrices ingresadas es: " << endl;
		
		int A[n][m];
    	
		for(int fila = 0; fila < n; fila++){
        	for(int col = 0; col < m; col ++){
            	
				A[fila][col] = Mat1[fila][col] + Mat2[fila][col];
            	cout << A[fila][col] << "\t";
        	}
        	cout << endl;
    	}	
	
	cout << "Deseas continuar (1: SI, 0: NO) " << endl;
		cin >> CONTINUAR;	
			
	}while( CONTINUAR == 1 );
	
	
	
	return 0;
}
