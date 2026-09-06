#include <iostream>
#include <vector>
using namespace std;

int main() {
    int capacidad = 5;
    vector<int> pila;
    int valor;
    cout << "Apilar" << endl;
    while (true) {
        try {
            if (pila.size() >= capacidad) {
                throw "lleno";
            }
            cout << "Ingresa un numero: ";
            cin >> valor;
            pila.push_back(valor);
        }
        catch (const char* mensaje) {
            cout << mensaje << endl;
            break; 
        }
    }
    cout << "\nElementos guardados en la pila: ";
    for (int i = 0; i < pila.size(); i++) {
        cout << pila[i] << " ";
    }
    cout << endl;
    cout << "\nDesapilar" << endl;
    while (true) {
        try {
            if (pila.empty()) {
                throw "vacia.";
            }

            cout << "Quitando de la pila el numero: " << pila.back() << endl;
            pila.pop_back();
        }
        catch (const char* mensaje) {
            cout << mensaje << endl;
            break; 
        }
    }

    return 0;
}