// INCLUIR LIBERIA
#include<iostream>

using namespace std;
int main(){
	
	cout << "PROBAR LA DECLARACION DE VARIABLES" << endl;
	
	int a = 24;
	int b = 35;
	int c = 24;
	
	cout << "a==" << a << endl;
	cout << "b==" << b << endl;
	cout << "c==" << c << endl;
	
	cout << "Es verdadero que a==c?" << endl;
	
	if(a < c){
		cout << "Variable a es menor a c" << endl;
	}else if( a > c){
		cout << "Variable a es mayor a c" << endl;
	}else{
		cout << "Variables a y c son iguales" << endl;
	}
	
	return 0;
}
