#include <iostream>
using namespace std;
const int numero_global = 8;

int sumatoria(int numerolocal) {
    int arreglo_numero[numero_global];
    int suma_total = 0;
    int suma_total2 = 0;
    for (int i = 0; i < numerolocal; i++) {
        cout << "Ingrese el valor: ";
        cin >> arreglo_numero[i];
        suma_total = suma_total + arreglo_numero[i];
        suma_total2 += arreglo_numero[i];
    }
    cout << "Suma total 1: " << suma_total << endl;
    cout << "Suma total 2: " << suma_total2 << endl;
    return suma_total;
}

int main() {
    int resultado = 0, cantidad = 0, resultado2 = 0;
    cout << "Actividad 02 - Sumatoria de arreglos estaticos\n" << endl;
    resultado = sumatoria(numero_global);
    cout << "El resultado de la sumatoria 1 es: "
        << resultado << endl;
    cout << "Ingrese la cantidad de numeros para la segunda sumatoria: ";
    cin >> cantidad;
    resultado2 = sumatoria(cantidad);
    cout << "El resultado de la sumatoria 2 es: "
        << resultado2 << endl;
    return 0;
}