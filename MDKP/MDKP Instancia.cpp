//EJEMPLOS de programacion para curso OPHEAP, febrero-junio 2021 (esto es un comentario)
#include <iostream>
#include <vector>
#include <time.h>   //clock()
#include <stdlib.h>

using namespace std;

struct INSTANCIA{
    int CardI;                     //Articulos
    int CardJ;	 				   //Dimensiones
    vector<int> capacidades;       //Vector de Capacidades
    vector<int> beneficios;        //beneficios
    vector< vector<int> > pesos;   //Martiz de pesos
};

struct SOLUTION{
    vector<int> x;              //Vector binarios
    int FnObj;                  //Valor de funcion objeto
    vector<int> CapRem;         //Capacidades remanentes
};


int main(){
    
    bool GREEDY = false;
    bool RANDOM = false;
    bool GREEDY_RANDOM = true;
    
        
    cout << "----------- INSTANCIA -----------" << endl;
    
	//----------------------- GENERAR INSTANCIA AL AZAR -----------------------
    srand( 1 );
    double t_inicial = clock();
    
    INSTANCIA A;
    A.CardI = 420;
    A.CardJ = 8;
    A.beneficios.resize( A.CardI );
    A.pesos.resize( A.CardI );
    A.capacidades.resize( A.CardJ );
		     
    vector<int> PesoI;    //Para calcular la suma de los pesos de todas dimension de un objeto
    PesoI.resize( A.CardI );
    
    for(int i = 0; i < A.CardI; i++){
        A.beneficios[i] = 20 + rand()%150;   //entre [20, 100]
        A.pesos[i].resize( A.CardJ );
        for(int j = 0; j < A.CardJ; j++){
          	A.pesos[i][j] = 10 + rand()%31;        //entre [10, 30]
           	A.capacidades[j] += A.pesos[i][j];
		}                
    }
        
    for(int j = 0; j < A.CardJ; j++){
       	A.capacidades[j] = A.capacidades[j]/3;
	}
    
	for(int i = 0; i < A.CardI; i++){
		for(int j = 0; j < A.CardJ; j++){
			PesoI[i] = PesoI[i] + A.pesos[i][j];
		}
	}  
        
    	    
    //IMPRIMIR INFO DE LA INSTANCIA
    cout << "n: " << A.CardI << endl;  // "Cantidad de articulos" 
    cout << "m: " << A.CardJ << endl; // "Dimensiones de la mochila" 
    cout << "b: [";  // "Beneficios de los articulos" 
    for( int i = 0; i < A.CardI; i++ ){
    	cout << A.beneficios[i] << "\t"; 
	}
    cout << " ]" << endl;
    cout << "w: ["; // "Pesos de los artuclos es sus respectivas dimensionnes"
    for( int i = 0; i < A.CardI; i++ ){
    	for( int j = 0; j < A.CardJ; j++ ){
    		cout << A.pesos[i][j] << "\t"; 
		}
		cout << endl; 
	}
	cout << " ]" << endl;
	cout << "W: ["; // "Capacidades de la mochila en sus respectivas dimensiones" 
	for( int j = 0; j < A.CardJ; j++ ){
		cout << A.capacidades[j] << "\t";
	}
	cout << " ]" << endl;

}
