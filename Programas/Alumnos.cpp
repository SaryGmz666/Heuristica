#include<iostream>
#include<string>

using namespace std;

struct ALUMNOS{
	int semestre;
	int edad;
	int matricula;
	double promedio;
};

struct NOMBRE{
	string nombre;
};

int main(){
	
	NOMBRE GPO001nom[5];
	ALUMNOS GPO001[5];
	
	// Nombres
	GPO001nom.nombre[0] = "Eric Pulido";
	GPO001nom.nombre[1] = "Sarai Gomez";
	GPO001nom.nombre[2] = "Daisy Beraza";
	GPO001nom.nombre[3] = "Corpus";
	GPO001nom.nombre[4] = "Yuliana";
	
	// Semestre
	GPO001.semestre[0] = 4;
	GPO001.semestre[1] = 9;
	GPO001.semestre[2] = 3;
	GPO001.semestre[3] = 2;
	GPO001.semestre[4] = 4;
	
	// Edad
	GPO001.edad[0] = 25;
	GPO001.edad[1] = 22;
	GPO001.edad[2] = 24;
	GPO001.edad[3] = 27;
	GPO001.edad[4] = 25;
	
	// Matricula
	GPO001.matricula[0] = 1628735;
	GPO001.matricula[1] = 1748263;
	GPO001.matricula[2] = 1592740;
	GPO001.matricula[3] = 1509376;
	GPO001.matricula[4] = 1693375;
	
	// Promedio
	GPO001.promedio[0] = 77;
	GPO001.promedio[1] = 82.5;
	GPO001.promedio[2] = 80.5;
	GPO001.promedio[3] = 97.3;
	GPO001.promedio[4] = 94.5;
	
	cout << "Nombre" << "\t" << "Semestre" << "\t" << "Edad" << "\t" << "Matricula" << "\t" << "Promedio" << endl;
	for(int pos = 0; pos < 5; pos++){
		cout << GPO001.nom.nombre[pos] << "\t" << GPO001.semestre[pos] << "\t" << GPO001.edad[pos] << "\t" << GPO001.matricula[pos] << "\t" << GPO001.promedio[pos] << endl;	
	}
	
	return 0;
}
