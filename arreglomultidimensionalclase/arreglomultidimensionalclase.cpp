#include <iostream>
using namespace std;
const int numero_filas = 3;
const int numero_columnas = 3;
// [i][j] { } <<  >> \

void imprimir_matriz(int matriz_local_imp[numero_filas][numero_columnas]) {
	for (int i = 0; i < numero_filas; i++) {
		for(int j = 0; j < numero_columnas ; j++) {
			cout << matriz_local_imp[i][j] << "";
		}
		cout << endl;
	}
}

void ingresar_valores(int matriz_local[numero_filas][numero_columnas]) {
	for (int i = 0; i < numero_filas; i++) {
		for (int j = 0; j < numero_columnas; j++) {
			cout << "Ingrese el valor para la posicion [" << i << "][" << j << "]: ";
			cin >> matriz_local[i][j];
		}
	}
}

int main() {
	cout << "actividad arreglo multidimensional act 03";
	int arreglo_matriz[numero_filas][numero_columnas];
	ingresar_valores(arreglo_matriz);
	imprimir_matriz(arreglo_matriz);
}



	

