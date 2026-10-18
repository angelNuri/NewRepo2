// 3JLSC-YairGonalez-13.cpp : Arbol Binario de Busqueda con menu, usando apuntadores de memoria en C++
// Cada nodo tiene como maximo dos hijos:
//   izquierdo -> valores MENORES que el nodo
//   derecho   -> valores MAYORES que el nodo

#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;
};

Nodo* CrearNodo(int valor) {
    Nodo* nuevoNodo = new Nodo; // Creamos el apuntador de la estructura
    nuevoNodo->dato = valor;
    nuevoNodo->izquierdo = nullptr;
    nuevoNodo->derecho = nullptr;
    return nuevoNodo;
}

// Inserta el valor bajando por el arbol hasta encontrar un lugar vacio
void AgregarNodo(Nodo*& raiz, int valor) {
    if (raiz == nullptr) {
        raiz = CrearNodo(valor);
        return;
    }
    Nodo* actual = raiz;
    while (true) {
        if (valor < actual->dato) {
            if (actual->izquierdo == nullptr) {
                actual->izquierdo = CrearNodo(valor);
                return;
            }
            actual = actual->izquierdo;
        }
        else if (valor > actual->dato) {
            if (actual->derecho == nullptr) {
                actual->derecho = CrearNodo(valor);
                return;
            }
            actual = actual->derecho;
        }
        else {
            cout << "El valor " << valor << " ya existe, no se agrega" << endl;
            return;
        }
    }
}

// Una hoja es un nodo sin hijo izquierdo ni derecho
void MostrarHojas(Nodo* nodo, int& contador) {
    if (nodo == nullptr) return;
    if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
        cout << nodo->dato << "  (Direccion: " << nodo << ")" << endl;
        contador++;
        return;
    }
    MostrarHojas(nodo->izquierdo, contador);
    MostrarHojas(nodo->derecho, contador);
}

// Preorden: nodo, izquierdo, derecho
void Preorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    cout << nodo->dato << " ";
    Preorden(nodo->izquierdo);
    Preorden(nodo->derecho);
}

// Inorden: izquierdo, nodo, derecho (muestra los valores ordenados)
void Inorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    Inorden(nodo->izquierdo);
    cout << nodo->dato << " ";
    Inorden(nodo->derecho);
}

// Postorden: izquierdo, derecho, nodo
void Postorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    Postorden(nodo->izquierdo);
    Postorden(nodo->derecho);
    cout << nodo->dato << " ";
}

// Muestra la estructura con sangria y las direcciones de memoria
void ImprimirArbol(Nodo* nodo, int nivel, string lado) {
    if (nodo == nullptr) return;
    for (int i = 0; i < nivel; i++) {
        cout << "    "; // Sangria segun el nivel
    }
    cout << lado << nodo->dato
        << " | Direccion: " << nodo
        << " | Izq: " << nodo->izquierdo
        << " | Der: " << nodo->derecho << endl;
    ImprimirArbol(nodo->izquierdo, nivel + 1, "I- ");
    ImprimirArbol(nodo->derecho, nivel + 1, "D- ");
}

// Postorden: se borran primero los hijos y al final el padre
void BorrarArbol(Nodo*& nodo, int& contador) {
    if (nodo == nullptr) return;
    BorrarArbol(nodo->izquierdo, contador);
    BorrarArbol(nodo->derecho, contador);
    cout << "Elemento borrado " << contador
        << " | Dato: " << nodo->dato
        << " | Direccion: " << nodo << endl;
    contador++;
    delete nodo;
    nodo = nullptr;
}

int main()
{
    Nodo* raiz = nullptr; // Declaracion del puntero inicial
    int opc;

    cout << "Actividad 13 - Arbol Binario de Busqueda\n" << endl;
    do
    {
        cout << "\n_____Menu Principal_____" << endl;
        cout << "1. Ingresar elementos_____" << endl;
        cout << "2. Mostrar hojas__________" << endl;
        cout << "3. Visualizar arbol_______" << endl;
        cout << "0. Salir__________________" << endl;
        cout << "==========================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opc;
        switch (opc)
        {
        case 1: {
            int cantidad;
            cout << "Ingrese la cantidad de elementos a agregar: ";
            cin >> cantidad;
            if (cantidad <= 0) {
                cout << "Cantidad no valida de elementos" << endl;
                break;
            }
            for (int i = 0; i < cantidad; i++) {
                int valor;
                cout << "Ingrese el valor " << i + 1 << ": ";
                cin >> valor;
                AgregarNodo(raiz, valor);
            }
            break;
        }
        case 2: {
            if (raiz == nullptr) {
                cout << "El arbol esta vacio" << endl;
                break;
            }
            int totalHojas = 0;
            cout << "Hojas del arbol:" << endl;
            MostrarHojas(raiz, totalHojas);
            cout << "Total de hojas: " << totalHojas << endl;
            break;
        }
        case 3: {
            if (raiz == nullptr) {
                cout << "El arbol esta vacio" << endl;
                break;
            }
            cout << "Estructura del arbol (R = raiz, I = izquierdo, D = derecho):" << endl;
            ImprimirArbol(raiz, 0, "R- ");

            cout << "\nPreorden:  "; Preorden(raiz);  cout << endl;
            cout << "Inorden:   "; Inorden(raiz);   cout << endl;
            cout << "Postorden: "; Postorden(raiz); cout << endl;
            break;
        }
        case 0: {
            cout << "Borrando arbol antes de salir:" << endl;
            int contador = 1;
            BorrarArbol(raiz, contador);
            cout << "Total de elementos borrados: " << contador - 1 << endl;
            cout << "Saliendo del programa..." << endl;
            break;
        }
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opc != 0);
    return 0;
}
