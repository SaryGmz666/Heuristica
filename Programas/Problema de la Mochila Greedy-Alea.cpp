#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct INSTANCIA{
	int CardI;					//Articulos
	int CapacidadMochila;		//Capacidad de la mochila
	vector<int> beneficios;		//beneficios
	vector<int> pesos;			//pesos
};

struct SOLUTION{
	vector<int> x;				//vector binario
	int FnObj;					//valor de la funcion objetivo
	int CapacidadRemanente;		//capacidad remanente
};

int main(){
	
	srand( 1 );
	double t_inicial = clock();
	
	//Crear una instancia aleatoria
	INSTANCIA A;
	A.CardI = 10;
	A.beneficios.resize( A.CardI );
	A.pesos.resize( A.CardI );
	A.CapacidadMochila = 0;
	for(int i = 0; i < A.CardI; i++){
		A.beneficios[i] = 50 + rand()%51;		//beneficios entre 50 y 100
		A.pesos[i] = 10 + rand()%21;			//beneficios entre 10 y 30
		cout << A.pesos[i]; 
		cout << "\t" << A.beneficios[i] << endl;
		A.CapacidadMochila += A.pesos[i];
	}
	A.CapacidadMochila = A.CapacidadMochila/2;
	
	cout << "La capacidad de la Mochila es: " << A.CapacidadMochila << endl;
	
	//---------------------------- Greedy Aleatorizado ----------------------------
	
	//Inicializacion de la solucion
	SOLUTION S;
	S.x.resize( A.CardI );
	S.FnObj = 0;
	S.CapacidadRemanente = A.CapacidadMochila;
	
	//Vector I que tiene los elementos que aun no son ingresados
	vector<int> Iprima;
	Iprima.resize( A.CardI );
	for(int pos = 0; pos < A.CardI; pos++)
		Iprima[pos] = pos;
	
	//Ordear Iprima
	for(int pos = 0; pos < A.CardI; pos++){
		for(int pos1 = 0; pos1 < A.CardI; pos1++){
			
			if( A.beneficios[(Iprima[pos1])]/A.pesos[(Iprima[pos1])] > A.beneficios[(Iprima[pos])]/A.pesos[(Iprima[pos])] ){
				int aux = Iprima[pos];
				Iprima[pos] = Iprima[pos1];
				Iprima[pos1] = aux;
			}
			
		}
	}
	
	int k = 3; 				//Tamaño de la lista restinguida si es 1 es aleatorio
							// si es del tamaño de Iprima.size() cae en greedy
		
	//Inicio del ciclo
	while( Iprima.size() > 0 and S.CapacidadRemanente > 0){
		
		// Encontrar i*
		int pos_i = 0;
		
		if( k <= Iprima.size() ){
			pos_i = rand() % k;
		}else{
			pos_i = rand() % Iprima.size();			
		}
			
		int i = Iprima[pos_i];
		
		
		// Intentar agregar i*
		if( A.pesos[i] <= S.CapacidadRemanente ){
			S.x[i] = 1;
			S.CapacidadRemanente -= A.pesos[i];
			S.FnObj += A.beneficios[i];
		}
		
		//Eliminar el articulo
		Iprima.erase( Iprima.begin() + pos_i );
	}
	
	double t_final = clock();
	
	cout << "Valor objetivo = " << S.FnObj << endl;
	cout << "ARTICULOS EN LA MOCHILA" << endl;
	for(int i = 0; i < A.CardI; i++){
		if(S.x[i] == 1)
			cout << "Articulo " << i << " con un peso de " << A.pesos[i] << " teniendo un beneficio de " << A.beneficios[i] << endl;
	}
	
	cout << "La capacidad remanente es: " << S.CapacidadRemanente << endl;
	cout << "El tiempo utilizado es: " << (double)(t_final - t_inicial)/(double)CLOCKS_PER_SEC << " segundos" << endl;
}
