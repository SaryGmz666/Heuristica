#include "MTRand.h"
#include "BRKGA.h"
#include "Instance.h"
#include "Decoder.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <string>
#include <limits>
#include <algorithm>
#include <stdexcept>
#include "math.h"

using namespace std;

int main() {
    //////////////////////////////////////////////////////
    ////////////////////  BRKGA //////////////////
    //////////////////////////////////////////////////////
    //NOTA: El algoritmo encuentra el cromosoma con el m’nimo valor de la funcion fitness
    unsigned long t0;
    t0 = clock();
    cout << "---- BRKGA ALGORITHM FOR THE KNAPSACK PROBLEM ----" << endl;
    //--- Leyendo y llenando instancia
    INSTANCE A;

    //--- CREAMOS AL AZAR

    A.CardI = 100;

    A.Beneficios.resize( A.CardI );

    A.Pesos.resize( A.CardI );

    A.Capacidad = 0;

    for(int i = 0; i < A.CardI; i++){

        A.Beneficios[i] = 50 + rand()%51;

        A.Pesos[i] = 50 + rand()%51;

        A.Capacidad += A.Pesos[i];

    }

    A.Capacidad = 0.5*A.Capacidad;
    
    
    //--- Declaracion de parametros BRKGA y criterios de paro
    bool CRITERIO_TIEMPO = false;
    double TIME_LIMIT = 60*10;               //Tiempo limite (segundos)
    bool CRITERIO_NUMERO_ITERACIONES = false;
    int ITER_LIMIT = 200;                    //Iteraciones limite
    bool CRITERIO_ITER_NO_IMPROVEMENT = true;
    int ITER_WITH_NO_IMPROVEMENT = 100;      //Iterations without improvement
    int GEN_PRINT = 1;                      //Imprimir cada GEN_PRINT iterations
    
	SampleDecoder decoder(& A);              // initialize the decoder
    const unsigned n = A.CardI;          	     // Tama–o del cromosoma
    const unsigned p = 100;                  // tama–o de poblacion
    const double pe = 0.2;                   // fraccion de la poblacion para ser elite-set
    const double pm = 0.1;                   // fraccion de la poblacion para ser remplazada por mutaciones
    const double rhoe = 0.75;                // probabilidad de heredar un alelo del padre elite
    const unsigned K = 1;                    // number of independent populations
    const unsigned MAXT = 1;                 // [??] number of threads for parallel decoding
    const long unsigned rngSeed = 0;         // seed to the random number generator
    MTRand rng(rngSeed);                     // initialize the random number generator

    
            
    //--- Initialize the BRKGA-based heuristic
    BRKGA < SampleDecoder, MTRand > algorithm(n, p, pe, pm, rhoe, decoder, rng, K, MAXT);
    unsigned generation = 0;                    // generacion actual
        
    // cout << "--- Iniciando generaciones del BRKGA ... " << endl;
    double execution_time = 0;
    double initial_time = clock();
    
    
    //El algoritmo minimiza
    if ( CRITERIO_TIEMPO ) {
        cout << "\t --- TIEMPO LIMITE: " << endl;
        do {
            algorithm.evolve();    // evolve the population for one generation
            cout << "BestFitness en iteracion " << generation << " == " << -algorithm.getBestFitness() << endl;
            generation ++;
            execution_time = (clock() - initial_time)/CLOCKS_PER_SEC;
            }while ( execution_time < TIME_LIMIT );
    }
    if ( CRITERIO_NUMERO_ITERACIONES ){
        cout << "\t --- NUMERO DE ITERACIONES: " << endl;
        do{
            algorithm.evolve();    // evolve the population for one generation
            cout << "BestFitness en iteracion " << generation << " == " << -algorithm.getBestFitness() << endl;
            generation ++;
        }while ( generation < ITER_LIMIT );
    }
    if ( CRITERIO_ITER_NO_IMPROVEMENT ) {
        double incumbent = -10000000;
        cout << "\t --- NUMERO DE ITERACIONES SIN MEJORA: " << endl;
        do{
            algorithm.evolve();    // evolve the population for one generation
            cout << "BestFitness en iteracion " << generation << " == " << -algorithm.getBestFitness() << endl;
            if( incumbent != algorithm.getBestFitness() ){
                incumbent = algorithm.getBestFitness();
                generation = 0;
            }else
                generation ++;
        } while( generation < ITER_WITH_NO_IMPROVEMENT ); //100 iteraciones sin mejora
    }
    execution_time = (clock() - initial_time)/CLOCKS_PER_SEC;

    
    
    //------------------------------------------- RECUPERAR MEJOR SOLUCION CON DECODER
    vector <double> best_chromosome = algorithm.getBestChromosome();
    
    
    //------------------------------------------- RECUPERAR MEJOR SOLUCION CON DECODER

    vector <double> chromosome = algorithm.getBestChromosome();
    double fitness = 0;

    //(1) Ordenar articulos I' decrecientemente en base al valor chromosome[i]
    vector <int> Iprima;
    Iprima.resize( A.CardI );
    for(int i = 0; i < A.CardI; i ++ )
        Iprima[i] = i;
 
    for(int pos = 0; pos < A.CardI; pos++){
        for(int pos1 = pos; pos1 < A.CardI; pos1++ ){
            if( chromosome[pos1] > chromosome[pos] ){
                int aux = Iprima[pos];
                Iprima[pos] = Iprima[pos1];
                Iprima[pos1] = aux;
            }
        }
    }

    //(2) Intentar meter artículos en el orden de I' (actualizar todo)
    int CapacidadRemanente = A.Capacidad;
    cout << "--- Articulos en la mochila: " << endl;
    for(int pos = 0; pos < Iprima.size(); pos++ ){
        int i = Iprima[pos];
        if( A.Pesos[i] <= CapacidadRemanente ){
            fitness += A.Beneficios[i];
            CapacidadRemanente -= A.Pesos[i];
            cout << i << endl;
        }
    }

    
    //fitness que se tiene que minimizar
    cout << "VALOR OBJETIVO == " << fitness << endl;
    cout << "CPU_TIME == " << execution_time << endl;
    cout << "CAPACIDAD REMANENTE == " << CapacidadRemanente << endl;

    return 0;
	  
}
