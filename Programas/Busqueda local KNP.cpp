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
    bool GREEDY_RANDOM = false;
    bool RANDOM = true;
    
    
    srand( time(NULL) );
    cout << "--- INSTANCIA KNAPSACK PROBLEM ---" << endl;
    cout << "articulo\tbeneficio\tpeso" << endl;
    for(int instancia = 1; instancia <= 1; instancia ++){
        //----------------------- GENERAR INSTANCIA AL AZAR -----------------------
        srand( instancia );
        INSTANCIA A;
        A.CardI = 102;
        A.beneficios.resize( A.CardI );
        A.pesos.resize( A.CardI );
        A.CapacidadMochila = 0;
        for(int i = 0; i < A.CardI; i++){
            A.beneficios[i] = 50 + rand()%51;   //entre [50, 100]
            A.pesos[i] = 10 + rand()%21;        //entre [10, 30]
            A.CapacidadMochila += A.pesos[i];
            cout << i << "\t\t" << A.beneficios[i] << "\t\t" << A.pesos[i] << endl;
        }
        A.CapacidadMochila = A.CapacidadMochila/2;
        
        cout << "Capacidad de Mochila == " << A.CapacidadMochila << endl;
        
        
        //------------------------- CONSTRUCTIVO --------------------------
        SOLUTION S;
        double CPU_TIME = 0;
        int k = 0;
        if( GREEDY )
            k = 1;
        if( RANDOM )
            k = A.CardI;
        if( GREEDY_RANDOM )
            k = 4;
        
        
        //inicia constructivo
        S.x.resize( A.CardI );
        S.FnObj = 0;
        S.CapacidadRemanente = A.CapacidadMochila;
                
        vector<int> Iprima;
        Iprima.resize( A.CardI );
        for(int pos = 0; pos < A.CardI; pos++)
            Iprima[pos] = pos;
                
        srand( time(NULL) + rand() );
        double t_inical = clock();
        
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
        CPU_TIME += (double)(t_final - t_inical)/(double)CLOCKS_PER_SEC;
        //Fin de constructivo
        
        
        //---- IMPRIMIR INFO DE SOLUCION
        cout << endl;
        cout << "--- SOLUCION FACTIBLE --- " << endl;
        cout << "VALOR OBJETIVO == " << S.FnObj << endl;
        cout << "CAPACIDAD REMANENTE == " << S.CapacidadRemanente << endl;
        cout << "TIEMPO == " << CPU_TIME << " segundos" << endl;
        cout << "ARTICULOS EN MOCHILA:" << endl;
        for(int i = 0; i < A.CardI; i ++){
            if( S.x[i] == 1 )
                cout << i << endl;
        }
        
        
        //--- Buesqueda local
        
        int LOCAL_OPTIMUM = 0;
        
        while( LOCAL_OPTIMUM == 0 ){
        	LOCAL_OPTIMUM = 1;
        	for(int i = 0; i < A.CardI; i++){
        		if( S.x[i] == 1 ){
        			for(int j = 0; j < A.CardI; j++){
        				if( S.x[j] == 0 ){
        					
        					//implementar operador
        					if( S.CapacidadRemanente + A.pesos[i] >= A.pesos[j] and A.beneficios[j] > A.beneficios[i] ){
        						S.x[i] = 0;
        						S.x[j] = 1;
        						S.CapacidadRemanente = S.CapacidadRemanente + A.pesos[i] - A.pesos[j];
        						S.FnObj = S.FnObj - A.beneficios[i] + A.beneficios[j];
        						LOCAL_OPTIMUM = 0;
        						break;
        					}
        					
						}					
					}
				}
				if( LOCAL_OPTIMUM == 0 ){
							break;
				}
			}
        	
		}
        
        //---- IMPRIMIR INFO DE SOLUCION
        cout << endl;
        cout << "--- SOLUCION FACTIBLE --- " << endl;
        cout << "VALOR OBJETIVO == " << S.FnObj << endl;
        cout << "CAPACIDAD REMANENTE == " << S.CapacidadRemanente << endl;
        cout << "TIEMPO == " << CPU_TIME << " segundos" << endl;
        cout << "ARTICULOS EN MOCHILA:" << endl;
        for(int i = 0; i < A.CardI; i ++){
            if( S.x[i] == 1 )
                cout << i << endl;
        }
        
    
    }
    cout << endl << "--- FIN DE PROGRAMA ---" << endl;
    
    return 0;
}
