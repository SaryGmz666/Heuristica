//
//  Instance.cpp
//  PPMMbrkga
//
//  Created by yasmin rios on 05/06/14.
//  Copyright (c) 2014 Yasmin. All rights reserved.
//

#include "Instance.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "Memory.h"
#include "MTRand.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <list>

using namespace std;


double max(double a, double b){
	if (a > b)
		return a;
	else
		return b;
	
};

double min(double a, double b){
	if( a < b )
		return a;
	else
		return b;
};

void lee(INSTANCE *A, string file_name){

    ifstream lee;		//reading functions
    lee.open( file_name.c_str() );
    if (lee.fail())
        cout << "Error al abrir archivos de lectura!!" << endl;
    //A partir de aquí nuestra funcion
    
    cout << "\t ---- REDING INSTANCE ----- " << endl;
        
    lee >> A->CardI;             //Lee cantidad de l’neas
    lee >> A->Capacidad;         //Lee capacidad de mochila
        
    
    
    cout << "\t ---- FINISHING READING INSTANCE ----" << endl;
    
    lee.close();
};






