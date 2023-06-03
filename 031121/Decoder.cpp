/*
 *  SampleDecoder.cpp
 *  Created on: Jan 14, 2011
 *  Author: rtoso
 */

#include "Decoder.h"
#include <iostream>
#include "Instance.h"
#include "math.h"
#include <vector>

using namespace std;

SampleDecoder::SampleDecoder(struct INSTANCE* instA):instance(instA){}

SampleDecoder::~SampleDecoder(){ }

double SampleDecoder::decode(const std::vector< double > & chromosome) const {

    double fitness = 0;

	//(1) Ordenar articulos I' decrecientemente en base al valor chromosome[i]
	vector <int> Iprima;
	Iprima.resize( instance->CardI );
	for(int i = 0; i < instance->CardI; i ++ )
		Iprima[i] = i;

	for(int pos = 0; pos < instance->CardI; pos++){
		for(int pos1 = pos; pos1 < instance->CardI; pos1++ ){
			if( chromosome[pos1] > chromosome[pos] ){
				int aux = Iprima[pos];
				Iprima[pos] = Iprima[pos1];
				Iprima[pos1] = aux;
			}
		}
	}

	//(2) Intentar meter artículos en el orden de I' (actualizar todo)
	int CapacidadRemanente = instance->Capacidad;
	for(int pos = 0; pos < Iprima.size(); pos++ ){
		int i = Iprima[pos];
		if( instance->Pesos[i] <= CapacidadRemanente ){
			fitness += instance->Beneficios[i];
			CapacidadRemanente -= instance->Pesos[i];
		}
	}

	//fitness que se tiene que minimizar
	return -fitness;
}




