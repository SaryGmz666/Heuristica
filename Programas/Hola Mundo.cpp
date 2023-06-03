// INCLUIR LIBERIA
#include<iostream>

// AHORRO DE SINTAXIS
using namespace std;

// Hola Mundo
//int main(){
	
//	cout << "Hola Mundo" << endl;
//	cout << "Mi primer programa en C++" << endl;
	
//	return 0;
//}

//Declaracion de variables
int main(){
	
	cout << "PROBAR LA DECLARACION DE VARIABLES" << endl;
	
	int a, b, c;
	int resul;
	
	cout << "El valor de a es:" << a << endl;
	cout << "El valor de b es:" << b << endl;
	
	//proceso
	a = 25;
	b = 35;
	c = 15;
	resul = a + 1;
	
	cout << "El valor de a es:" << a << endl;
	cout << "El valor de b es:" << b << endl;
	cout << "El valor de result es:" << resul << endl;
	
	a = 30;
	cout << "El valor de result actualizado es:" << resul << endl;
	
	resul += a;
	cout << "El valor de result es:" << resul << endl;
	
	a -= b;
	cout << "El valor de a es:" << a << endl;
	
	b /= a;
	cout << "El valor de b es:" << b << endl;
	
	resul /= b;
	cout << "El valor de result es:" << resul << endl;
	
	cout << "COMPARACIONES" << endl;
	a = 25;
	b = 35;
	c = 15;
	resul = a + 1;	
	
	cout << "El valor de a es diferente al de b " << ( a != b) << endl;
	cout << "El valor de b es menor al de c " << (b < c) << endl;
	cout << "El valor de c es igual al de result " << (c == resul) << endl;
	cout << "El valor de a + b es mayor al de c " << (a+b > c) << endl;
	cout << "El valor de c+b es menor o igual al de result " << (c+b <= resul) << endl;
	
	return 0;
}
