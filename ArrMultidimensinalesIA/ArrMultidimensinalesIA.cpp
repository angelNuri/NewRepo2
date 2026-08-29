#include <iostream>
#include <limits>

using namespace std;

// Dimensiones de la matriz (filas x columnas), conocidas en tiempo de compilacion
constexpr int NUMERO_FILAS = 3;
constexpr int NUMERO_COLUMNAS = 3;

// Imprime el contenido de la matriz separando cada valor con un espacio.
// Recibe la matriz por referencia constante porque solo la lee, nunca la modifica.
void imprimir_matriz(const int(&matriz)[NUMERO_FILAS][NUMERO_COLUMNAS]) {
    for (int i = 0; i < NUMERO_FILAS; i++) {
        for (int j = 0; j < NUMERO_COLUMNAS; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
}

// Solicita al usuario el valor de cada posicion de la matriz.
// Si la entrada no es un numero valido, limpia el estado de error de cin
// y vuelve a pedir el dato en lugar de dejar el programa en un estado invalido.
void ingresar_valores(int(&matriz)[NUMERO_FILAS][NUMERO_COLUMNAS]) {
    for (int i = 0; i < NUMERO_FILAS; i++) {
        for (int j = 0; j < NUMERO_COLUMNAS; j++) {
            cout << "Ingrese el valor para la posicion [" << i << "][" << j << "]: ";
            while (!(cin >> matriz[i][j])) {
                cout << "Entrada invalida. Ingrese un numero entero: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
}

int main() {
    cout << "Actividad arreglo multidimensional act 03\n";

    int arreglo_matriz[NUMERO_FILAS][NUMERO_COLUMNAS];

    ingresar_valores(arreglo_matriz);
    imprimir_matriz(arreglo_matriz);

    return 0;
}