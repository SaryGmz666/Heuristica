//Segunda Parte del Examen parcial
//Multidimensional Knapsack Problem - MKP

#include <iostream>
#include <vector>
#include <time.h>   //clock()
#include <fstream>
#include <stdlib.h>

using namespace std;

//Generador de Instancia
struct INSTANCIA{
    int CardI;                  //Articulos
    int CardJ;
    vector<int> capacidades;       //Capacidad de mochila
    vector<int> beneficios;     //beneficios
    vector< vector< int > >  pesos;          //pesos
};

struct SOLUTION{
    vector<int> x;              //Vector binarios
        int FnObj;
    vector <int> CapRem;     //Capacidad remanente
};



int main(int argc, const char * argv[]){

    string FileName = argv[1];
    ifstream lee;
    lee.open( FileName.c_str() );
    if( lee.fail() )
        cout << "ERROR redind the input file!!" << endl;
    
    //ABRIR ARCHIVO
    INSTANCIA A;
    lee >> A.CardI;
    lee >> A.CardJ;
    A.capacidades.resize(A.CardJ);
    
    for( int j = 0; j < A.CardJ; j++){
    	lee >> A.capacidades[j];
	}
    
    A.beneficios.resize(A.CardI);
    A.pesos.resize(A.CardI);
    for(int i = 0; i < A.CardI; i++ ){
        A.pesos[i].resize(A.CardJ);
        lee >> A.beneficios[i];
    }
    
    for(int i = 0; i < A.CardI; i++){
        for(int j = 0; j < A.CardJ; j++){
            lee >> A.pesos[i][j];
        }
    }
    
    
    lee.close();
    
    cout << "----------- SOLUCION INICIAL -----------" << endl;
    double t_inicial = clock();
    
	bool GREEDY = true;
    bool RANDOM = false;
    bool GREEDY_RANDOM = false;
    
    vector<int> PesoI;    //Para calcular la suma de los pesos de todas dimension de un objeto
    PesoI.resize( A.CardI );
    for(int i = 0; i < A.CardI; i++){
		for(int j = 0; j < A.CardJ; j++){
			PesoI[i] = PesoI[i] + A.pesos[i][j];
		}
	}  
    
			
	for(int i = 0; i < A.CardI; i++){
		double razon = 0;
		razon = (double)A.beneficios[i]/(double)PesoI[i];
	}
    
	//Inicializacion de la solucion
	SOLUTION S;
	
	int k = 0;
        if( GREEDY )
            k = 1;
        if( RANDOM )
            k = A.CardI;
        if( GREEDY_RANDOM )
            k = 4;
	
	S.x.resize( A.CardI );
	S.CapRem.resize( A.CardJ );
	S.FnObj = 0;
	for(int j = 0; j < A.CardJ; j++){
		S.CapRem[j] = A.capacidades[j];
	}
	
	int SumCapRem = 0;
		
	for(int j = 0; j < A.CardJ; j++){
		SumCapRem += S.CapRem[j];
	}
	
	for(int i = 0; i < A.CardI; i++){
		S.x[i] = 0;
	}
			    	
    //Vector I que tiene los elementos que aun no son ingresados
	vector<int> Iprima;
	Iprima.resize( A.CardI );
	for(int pos = 0; pos < A.CardI; pos++)
		Iprima[pos] = pos;
		
		
	
	//ORDENAR Iprima en base al criterio escogido
	int n = 0;
	while( n <= A.CardI ){
	
		for( int pos = 0; pos < A.CardI - 1; pos ++ ){
			int i = Iprima[pos];
			int i1 = Iprima[pos + 1];
				
			if( (double)A.beneficios[i]/(double)PesoI[i] < (double)A.beneficios[i1]/(double)PesoI[i1] ){
            	int aux = Iprima[pos];
                Iprima[pos] = Iprima[pos + 1];
                Iprima[pos + 1] = aux;
                
        	}    
		}
		n += 1;	
	}		
	
	
	//Inicio del ciclo	
	while( Iprima.size() > 0 ){
		
		// Encontrar i* = argmax{b[i]/Sum_j w[i][j]} i en Iprima
        int pos_i = 0;
        if( k <= Iprima.size() )
            pos_i = rand() % k;
        else
            pos_i = rand() % Iprima.size();
        int i = Iprima[pos_i];
            
		
		// Intentar agregar i*
		int Check = 0;
		
		for(int j = 0; j < A.CardJ; j++){
			if( A.pesos[i][j] <= S.CapRem[j] ){
				Check += 1;
			}else{
				Check += 0;
			}
		}
		
		if( Check == A.CardJ ){
			S.x[i] = 1;
			S.FnObj += A.beneficios[i];
			for(int j = 0; j < A.CardJ; j++){
				S.CapRem[j] -= A.pesos[i][j];
				SumCapRem -= A.pesos[i][j];
			}
		}
		
		//Eliminar el articulo
		Iprima.erase( Iprima.begin() + pos_i );		
			
	}
	
	//IMPRIMIR INFO DE LA SOLUCION INICIAL
	vector<int> SPesoIngresados;
	SPesoIngresados.resize( A.CardJ );
	for( int j = 0; j < A.CardJ; j++ ){
		SPesoIngresados[j] = 0;
	}
		
	cout << "Valor objetivo = " << S.FnObj << endl;
	//cout << "Articulos en la mochila: " << endl;
	for(int i = 0; i < A.CardI; i++){
		if(S.x[i] == 1){
			//cout << "Articulo " << i+1  << " teniendo un beneficio de " << A.beneficios[i] << endl;
			for( int j = 0; j < A.CardJ; j++ ){
				SPesoIngresados[j] += A.pesos[i][j];
			}
		}			
	}
	
	for( int j = 0; j < A.CardJ; j++ ){
		//cout << "Capacidad usada en la dimension " << j+1 << ": " << SPesoIngresados[j] << " con un restante de: " << A.capacidades[j] - SPesoIngresados[j] << endl;
	}
	
	//cout << "La suma de las capacidades remanente es: " << SumCapRem << endl;
	
		
	cout << endl;
	cout << "----------- INICIA VND -----------" << endl;
	
	int l = 1;
	int conV1 = 0;
	int conV2 = 0;
	int conV3 = 0;
	int FnObjIni;
	FnObjIni = S.FnObj;
	vector<int> xIni;
	xIni.resize( A.CardI );
	
	for(int i = 0; i < A.CardI; i++){
		xIni[i] = S.x[i];
	}
	
	while( l < 4 ){
		//cout << "l tiene un valor de " << l << endl;
		if( l == 1 ){
			
			for(int i = 0; i < A.CardI; i++){
		        if( S.x[i] == 1 ){
		        	for(int j = 0; j < A.CardI; j++){
		        		if( S.x[j] == 0 ){
		        				
		        			//implementar operador
		        			int Check = 0;
							
							for(int k = 0; k < A.CardJ; k++){
								if( S.CapRem[k] + A.pesos[i][k] >= A.pesos[j][k] ){
									Check += 1;
								}else{
									Check += 0;
								}
							}
							
							if( Check == A.CardJ and A.beneficios[j] > A.beneficios[i] ){
		        				S.x[i] = 0;
		        				S.x[j] = 1;
		        				//cout << "Mejor valor encontrado en la vecindad 1" << endl;
		        				conV1 = conV1 +1;
		        				for(int k = 0; k < A.CardJ; k++){
		        					S.CapRem[k] = S.CapRem[k] + A.pesos[i][k] - A.pesos[j][k];
								}
								
		        				S.FnObj = S.FnObj - A.beneficios[i] + A.beneficios[j];
		        				break;
		        			}	
						}				
					}
				}	
			}
		}
		
		if ( l == 2 ){
			
			//Segundo vecindario
			//cout << "Entra vecindad 2 " << endl;
			for(int i = 0; i < A.CardI; i++){
        		if( S.x[i] == 1 ){
        		for(int j = 0; j < A.CardI; j++){
        			if( S.x[j] == 1 and i != j){
        			for(int k = 0; k < A.CardI; k++){
        				if( S.x[k] == 0 ){
							//implementar operador
        					int Check = 0;
							
							for(int r = 0; r < A.CardJ; r++){
								if( S.CapRem[r] + A.pesos[i][r] + A.pesos[j][r] >= A.pesos[k][r] ){
									Check += 1;
								}else{
									Check += 0;
								}
							}
							
							
							if( Check == A.CardJ and A.beneficios[j] + A.beneficios[i] < A.beneficios[k] ){
        						S.x[i] = 0;
        						S.x[j] = 0;
        						S.x[k] = 1;
        						//cout << "Mejor valor encontrado en la vecindad 2" << endl;
        						conV2 = conV2 +1;
	        					for(int r = 0; r < A.CardJ; r++){
									S.CapRem[r] = S.CapRem[r] + A.pesos[i][r] + A.pesos[j][r] - A.pesos[k][r];
								}
							
	        					S.FnObj = S.FnObj - A.beneficios[i] - A.beneficios[j] + A.beneficios[k];
	        					break;
        					}
							
						}
        			}
        			}if( FnObjIni < S.FnObj ){
        				break;	
					}
				}
				}
			}
			
		}
		
		if ( l == 3 ){
			
			//Segundo vecindario
			//cout << "Entra vecindad 3 " << endl;
			for(int i = 0; i < A.CardI; i++){
        		if( S.x[i] == 1 ){
        		for(int j = 0; j < A.CardI; j++){
        			if( S.x[j] == 0 ){
        			for(int k = 0; k < A.CardI; k++){
        				if( S.x[k] == 0 and k != j){
							//implementar operador
        					int Check = 0;
							
							for(int r = 0; r < A.CardJ; r++){
								if( S.CapRem[r] + A.pesos[i][r] >= A.pesos[k][r] + A.pesos[j][r] ){
									Check += 1;
								}else{
									Check += 0;
								}
							}
							
							
							if( Check == A.CardJ and A.beneficios[i] < A.beneficios[k] + A.beneficios[j]) {
        						S.x[i] = 0;
        						S.x[j] = 1;
        						S.x[k] = 1;
        						//cout << "Mejor valor encontrado en la vecindad 3" << endl;
        						conV3 = conV3 + 1;
	        					for(int r = 0; r < A.CardJ; r++){
									S.CapRem[r] = S.CapRem[r] + A.pesos[i][r] - A.pesos[j][r] - A.pesos[k][r];
								}
							
	        					S.FnObj = S.FnObj - A.beneficios[i] + A.beneficios[j] + A.beneficios[k];
	        					break;
        					}
														
						}
        			}
        			}if( FnObjIni < S.FnObj ){
        				break;
				}
				}
			}
			}
			
		}
		
		//cout << FnObjIni << " Valor actualizado " << S.FnObj << endl;
				
		//cout << endl;
		if( FnObjIni < S.FnObj ){
			
			//cout << "Solucion xIni" << endl;
			for( int i = 0; i < A.CardI; i++){
				//cout << xIni[i] << " ";
			}
			//cout << endl;
			//cout << "Solucion S.x" << endl;
			for( int i = 0; i < A.CardI; i++){
				//cout << S.x[i] << " ";
			}
			//cout << endl;
			l = 1;
			FnObjIni = S.FnObj;
			for(int i = 0; i < A.CardI; i++){
				xIni[i] = S.x[i];
			}
			//cout << FnObjIni << " Valor actualizado " << S.FnObj << endl;
			//cout << endl;	
		
			
		}else{
			//cout << "No se encontro mejora en la Vecindad " << l << endl;
			l += 1;
			//cout << endl;
		}
	}
	


	//cout << endl;
    cout << "----------- SOLUCION FINAL -----------" << endl;
    
	//Imprimir la solucion
	for( int j = 0; j < A.CardJ; j++ ){
		SPesoIngresados[j] = 0;
	}
	
	cout << "Valor objetivo = " << S.FnObj << endl;
	//cout << "Articulos en la mochila: " << endl;
	for(int i = 0; i < A.CardI; i++){
		if(S.x[i] == 1){
			//cout << "Articulo " << i+1  << " teniendo un beneficio de " << A.beneficios[i] << endl;
			for( int j = 0; j < A.CardJ; j++ ){
				SPesoIngresados[j] += A.pesos[i][j];
			}
		}			
	}
	
	for( int j = 0; j < A.CardJ; j++ ){
		//cout << "Capacidad usada en la dimension " << j+1 << ": " << SPesoIngresados[j] << " con un restante de: " << A.capacidades[j] - SPesoIngresados[j] << endl;
	}
	
	
		
	
	double t_final = clock();
	cout << "Articulos: " << A.CardI << "\t" << "Dimensiones: " << A.CardJ << endl;
	cout << "El tiempo utilizado es: " << (double)(t_final - t_inicial)/(double)CLOCKS_PER_SEC << " segundos" << endl;
    cout << "Usamos " << conV1 << " veces la vecindad 1" << endl;
    cout << "Usamos " << conV2 << " veces la vecindad 2" << endl;
    cout << "Usamos " << conV3 << " veces la vecindad 3" << endl;
    cout << "--- FIN DE PROGRAMA ---" << endl;
    
    return 0;
}
