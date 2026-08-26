#include <iostream>

using namespace std;

const int numero_de_filas = 3;
const int numero_de_columnas = 3;


void imprimir_matriz(int matriz_local_imp[numero_de_filas][numero_de_columnas]) {
	printf("Los valores de matriz son \n");
	for (int i = 0, i < numero_de_filas i++) {
		for (int j = 0; j < numero_de_columnas; j++) {
			cout << matriz_local_imp[i][j] << " ";
		}
		cout << endl;

	}
}

void ingresar_valores_matriz(int matriz_local[numero_de_filas][numero_de_columnas]) {
	for (int i = 0; i < numero_de_filas;i++) {
		for (int j = 0; j < numero_de_columnas;j++) {
			printf("Ingrese el valor de la posición [%d] [%d] : \n", i + 1, j + 1);
			cin >> matriz_local[i][j];
		}
	}
}

int main()
{
	cout << "Actividad 03 - Arreglo Bidimension (Matriz MxN) \n";
	int arreglo_matriz[numero_de_filas][numero_de_columnas];
	ingresar_valores_matriz(arreglo_matriz);
	imprimir_matriz(arreglo_matriz);

}