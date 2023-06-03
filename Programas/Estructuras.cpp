#include<iostream>

using namespace std;

struct PRODUCT{
	double weight;
	double price;
};



int main(){
	
	// Declaracion de los productos, sin datos
	PRODUCT apple, banana, melon;
	double dato;
	
	cout << "Cuanto pesa la manzana?" << endl;
		cin >> dato;
		apple.weight = dato;
	
	cout << "Cuanto cuesta la manzana?" << endl;
		cin >> dato;
		apple.price = dato;
		
	cout << " " << endl;
		
	cout << "Cuanto pesa la banana?" << endl;
		cin >> dato;
		banana.weight = dato;
	
	cout << "Cuanto cuesta la banana?" << endl;
		cin >> dato;
		banana.price = dato;
		
	cout << " " << endl;
		
	cout << "Cuanto pesa la melon?" << endl;
		cin >> dato;
		melon.weight = dato;
	
	cout << "Cuanto cuesta la melon?" << endl;
		cin >> dato;
		melon.price = dato;	
		
	cout << " " << endl;
	
	cout << "Los pesos y costos de los productos son: " << endl;
	
	cout << " " << "\t" << "Peso" << "\t" << "Costo" << endl;
	cout << "Manzana" << "\t" << apple.weight << "\t" << apple.price << endl;	
	cout << "Bnana" << "\t" << banana.weight << "\t" << banana.price << endl;	
	cout << "Melon" << "\t" << melon.weight << "\t" << melon.price << endl;	
	cout << " " << endl;
		
	// Segunda parte del codigo
	
	PRODUCT ListaProductos[10];
	
	ListaProductos[0].weight = 100;
	ListaProductos[0].price = 50;
	
	ListaProductos[1].weight = 100;
	ListaProductos[1].price = 50;
	
	cout << "LISTA DE PRODUCTOS" << endl;
	
	for(int pos = 0; pos < 10; pos++){
		cout << ListaProductos[pos].weight << endl;
		cout << ListaProductos[pos].price << endl;
	}
	
	return 0;
}
