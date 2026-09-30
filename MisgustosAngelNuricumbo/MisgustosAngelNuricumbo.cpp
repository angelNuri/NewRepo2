#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// ---------------------------------------------------------
// Constantes globales
// ---------------------------------------------------------
const string NOMBRE_PROYECTO = "MisGustos TuNombre"; // Reemplaza "TuNombre" por tu nombre
const string TEMA = "Tecnologias";
const int TAM = 6;
const int FILAS = 2;
const int COLUMNAS = 3;

// ---------------------------------------------------------
// Funcion matriz: copia el arreglo estatico a una matriz 2x3
// ---------------------------------------------------------
void matriz(const string arreglo[], string mat[FILAS][COLUMNAS]) {
    int indice = 0;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            mat[i][j] = arreglo[indice];
            indice++;
        }
    }
}

// ---------------------------------------------------------
// Funcion pila: guarda los 6 elementos en un vector (pila)
// y luego agrega 2 tecnologias adicionales con push_back
// ---------------------------------------------------------
void pila(const string arreglo[], vector<string>& p) {
    p.clear(); // Evita duplicados si se ejecuta varias veces

    // Se apilan los 6 elementos del arreglo
    for (int i = 0; i < TAM; i++) {
        p.push_back(arreglo[i]);
    }

    // Se apilan 2 tecnologias adicionales
    p.push_back("React");
    p.push_back("AWS");
}

// ---------------------------------------------------------
// Funcion de impresion: muestra la matriz 2x3 y la pila final
// ---------------------------------------------------------
void imprimir(const string mat[FILAS][COLUMNAS], const vector<string>& p,
    bool matrizLista, bool pilaLista) {
    cout << "\n===== CONTENIDO DE LA MATRIZ 2x3 =====" << endl;
    if (matrizLista) {
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                cout << "[" << mat[i][j] << "]\t";
            }
            cout << endl;
        }
    }
    else {
        cout << "La matriz aun no ha sido generada (use la opcion 1)." << endl;
    }

    cout << "\n===== CONTENIDO FINAL DE LA PILA =====" << endl;
    if (pilaLista) {
        // Se imprime desde el tope (ultimo elemento) hasta la base
        for (int i = (int)p.size() - 1; i >= 0; i--) {
            cout << (i == (int)p.size() - 1 ? "TOPE -> " : "         ")
                << p[i] << endl;
        }
    }
    else {
        cout << "La pila aun no ha sido generada (use la opcion 2)." << endl;
    }
    cout << endl;
}

// ---------------------------------------------------------
// Muestra el menu principal
// ---------------------------------------------------------
void mostrarMenu() {
    cout << "======================================" << endl;
    cout << "  " << NOMBRE_PROYECTO << endl;
    cout << "  Tema: " << TEMA << endl;
    cout << "======================================" << endl;
    cout << "1. Generar matriz 2x3" << endl;
    cout << "2. Generar pila (con push de React y AWS)" << endl;
    cout << "3. Imprimir matriz y pila" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

// ---------------------------------------------------------
// Funcion principal
// ---------------------------------------------------------
int main() {
    // Arreglo estatico inicial de 6 elementos
    string tecnologias[TAM] = { "C++", "Python", "Linux", "Docker", "SQL", "Git" };

    string mat[FILAS][COLUMNAS];
    vector<string> p;

    bool matrizLista = false;
    bool pilaLista = false;
    int opcion = 0;

    // Ciclo continuo del menu
    while (opcion != 4) {
        mostrarMenu();

        // Validacion de entrada numerica
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nEntrada invalida. Ingrese un numero.\n" << endl;
            opcion = 0;
            continue;
        }

        switch (opcion) {
        case 1:
            matriz(tecnologias, mat);
            matrizLista = true;
            cout << "\nMatriz 2x3 generada correctamente.\n" << endl;
            break;
        case 2:
            pila(tecnologias, p);
            pilaLista = true;
            cout << "\nPila generada correctamente (8 elementos).\n" << endl;
            break;
        case 3:
            imprimir(mat, p, matrizLista, pilaLista);
            break;
        case 4:
            cout << "\nSaliendo del programa. Hasta luego." << endl;
            break;
        default:
            cout << "\nOpcion no valida. Intente de nuevo.\n" << endl;
            break;
        }
    }

    return 0;
}