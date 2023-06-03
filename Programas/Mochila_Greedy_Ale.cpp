//EJEMPLOS de programacion para curso OPHEAP, febrero-junio 2021 (esto es un comentario)
#include <iostream>
#include <vector>
#include <time.h>   //clock()
#include <stdlib.h>

using namespace std;

struct INSTANCIA{
    int CardI;                  //Articulos
    int CapacidadMochila;       //Capacidad de mochila
    vector<int> beneficios;     //beneficios
    vector<int> pesos;          //pesos
};

struct SOLUTION{
    vector<int> x;              //Vector binarios
    int FnObj;                  //Valor de funcion objeto
    int CapacidadRemanente;     //Capacidad remanente
};


//Greedy - Para cada instancia: reportar solución y tiempo
//Aleatorio Puro ( 500 ) - Para cada instancia: reportar la mejor solución y tiempo promedio
//Greedy-Aleatorizado ( 500 ) - Para cada instancia: reportar la mejor solución y tiempo promedio

int main(){
    
    bool GREEDY = false;
    bool RANDOM = false;
    bool GREEDY_RANDOM = true;
    
    
    
    cout << "--- CONSTRUCTIVOS Y BUSQUEDA LOCAL ---" << endl;
    for(int instancia = 1; instancia <= 10; instancia ++){
        //----------------------- GENERAR INSTANCIA AL AZAR -----------------------
        srand( instancia );
        INSTANCIA A;
        A.CardI = 100;
        A.beneficios.resize( A.CardI );
        A.pesos.resize( A.CardI );
        A.CapacidadMochila = 0;
        for(int i = 0; i < A.CardI; i++){
            A.beneficios[i] = 50 + rand()%101;   //entre [50, 100]
            A.pesos[i] = 10 + rand()%21;        //entre [10, 30]
            A.CapacidadMochila += A.pesos[i];
        }
        A.CapacidadMochila = A.CapacidadMochila/2;
             
        
        //------------------------- GREEDY ALEATORIZADO --------------------------
        SOLUTION S;
        
        int MejorFnObj = 0;
    	double Time_pro = 0;
        
        
        for(int Sol = 0; Sol < 500; Sol++){
        	S.x.resize( A.CardI );
        	S.FnObj = 0;
        	S.CapacidadRemanente = A.CapacidadMochila;
        
    	    vector<int> Iprima;
    	    Iprima.resize( A.CardI );
    	    for(int pos = 0; pos < A.CardI; pos++)
    	        Iprima[pos] = pos;
                
    	    //ORDENAR Iprima en base al criterio greedy
    	    for(int pos = 0; pos < A.CardI - 1; pos ++){
    	        int i = Iprima[pos];
    	        for(int pos1 = pos + 1; pos1 < A.CardI; pos1++){
    	            int i1 = Iprima[pos1];
    	            if( (double)A.beneficios[i1]/(double)A.pesos[i1] > (double)A.beneficios[i]/(double)A.pesos[i] ){
    	                int aux = Iprima[pos];
    	                Iprima[pos] = Iprima[pos1];
    	                Iprima[pos1] = aux;
    	            }
    	        }
    	    }        
        
    	    //ITERACIONES PRINCIPALES
    	    int k = 0;
    	    if( GREEDY )
    	        k = 1;
    	    if( RANDOM )
    	        k = A.CardI;
    	    if( GREEDY_RANDOM )
    	        k = 4;
        
    	    srand( time(NULL) + rand());
    	    double t_inical = clock();
    	    while( Iprima.size() > 0 and S.CapacidadRemanente > 0  ){
    	        // Encontrar i* = argmax{b[i]/w[i]} i en Iprima
    	        int pos_i = 0;
    	        if( k <= Iprima.size() )
    	            pos_i = rand() % k;
    	        else
    	            pos_i = rand() % Iprima.size();
    	        int i = Iprima[pos_i];
            
    	        // Intentar agregar i*
    	        if( A.pesos[i] <= S.CapacidadRemanente ){
    	            S.x[i] = 1;
    	            S.CapacidadRemanente -= A.pesos[i];
    	            S.FnObj += A.beneficios[i];
    	        }
    	        Iprima.erase( Iprima.begin() + pos_i );
    	    }
    	    double t_final = clock();
            
            //Tiempo
        	Time_pro += (double)(t_final - t_inical)/(double)CLOCKS_PER_SEC;
			//cout << S.FnObj << endl;
			
			//Busqueda de la mejor solucion
			if(MejorFnObj < S.FnObj){
				MejorFnObj = S.FnObj;
			}    
    	    
		}
		
		
        //IMPRIMIR INFO DE SOLUCION
        	cout << "INTANCIA " << instancia << endl;
    	    cout << "MEJOR VALOR OBJETIVO = " << MejorFnObj << endl;
    	    cout << "TIEMPO PROMEDIO == " << Time_pro/500 << " segundos" << endl;
    	    	
    
    }
    cout << "--- FIN DE PROGRAMA ---" << endl;
    
    return 0;
}
