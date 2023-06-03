// PROBLEMA 1
#include<iostream>

using namespace std;
int main(){
	
	char x;
	char a, e, i, o, u;
	int A, E, I, O, U;
	
	A, E, I, O, U = 0;
	
	for( int j=1; j<=5; j++){
		cout << "Ingresa un caracter "<< endl;
		cin >> x;
		
		if( x == a){
			A += 1;
		}else if( x == e){
			E += 1;
		}else if( x == i){
			I += 1;
		}else if( x == o){
			O += 1;
		}else if( x == u){
			U += 1;
		}
	}
	
	cout <<"Se ingresaron "<< A << " a" << endl;
	cout <<"Se ingresaron "<< E << " e" << endl;
	cout <<"Se ingresaron "<< I << " i" << endl;
	cout <<"Se ingresaron "<< O << " o" << endl;
	cout <<"Se ingresaron "<< U << " u" << endl;
		
return 0;
}
