#include <iostream>
using namespace std;
const int max_filas = 10;
const int max_columnas = 10;

int main() {
	int matriz[max_filas][max_columnas];
	int filas, columnas;
	cout << "ingrese elnumero de filas: ";
	cin >> filas;
	cout << "ingrese el numero de columnas: ";
	cin >> columnas;

	for (int i= 0; i < filas; i++) {
		for (int j = 0; j< columnas; j++) {
			cout << "ingresar los elementos de i,j: ";
			cin >> matriz[i][j];
			
		}
	}

	cout << "matriz: ";
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			cout << matriz[i][j] << " ";
		 }
		cout << endl;
	}

	return 0;
}
