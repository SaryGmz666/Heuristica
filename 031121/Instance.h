//
//  Instance.h
//  PPMMbrkga
//  Created by yasmin rios on 05/06/14.
//  Copyright (c) 2014 Yasmin. All rights reserved.
//

#ifndef __PPMMbrkga__Instance__
#define __PPMMbrkga__Instance__
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

struct INSTANCE{
    int CardI;                  //Cantidad de artículos de knapsack problem
    int Capacidad;              //Capacidad de la mochila
    vector <int> Pesos;         //Vector de pesos de artículos en la mochila
    vector <int> Beneficios;    //Vector de beneficios en artículos de la mochila
};


double max(double a, double b);
double min(double a, double b);
void lee(INSTANCE *Instancia, string file_name);

#endif /* defined(__PPMMbrkga__Instance__) */
