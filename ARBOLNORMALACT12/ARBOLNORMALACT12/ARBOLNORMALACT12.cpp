// 3JLSC-YairGonzalez-12_262c.cpp :  Arbol General con menu, usando apuntadores de memoria en C++
// Representacion "primer hijo - siguiente hermano":
// cada nodo apunta a su PRIMER hijo y a su SIGUIENTE hermano.
// Asi, los hijos de un nodo forman una lista enlazada simple.

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* hijo;     // Primer hijo (baja un nivel)
    Nodo* hermano;  // Siguiente hermano (mismo nivel)
};

Nodo* CrearNodo(int valor) {
    Nodo* nuevoNodo = new Nodo; // Creamos el apuntador de la estructura
    nuevoNodo->dato = valor;
    nuevoNodo->hijo = nullptr;
    nuevoNodo->hermano = nullptr;
    return nuevoNodo;
}

// Agrega un hijo al final de la lista de hijos del padre
// (igual que AgregarNodo en la lista enlazada)
Nodo* AgregarHijo(Nodo* padre, int valor) {
    Nodo* nuevoNodo = CrearNodo(valor);
    if (padre->hijo == nullptr) {
        padre->hijo = nuevoNodo;
    }
    else {
        Nodo* actual = padre->hijo;
        while (actual->hermano != nullptr) {
            actual = actual->hermano;
        }
        actual->hermano = nuevoNodo;
    }
    return nuevoNodo;
}

// Pide al usuario los hijos de cada nodo de forma recursiva
void ConstruirArbol(Nodo* nodo) {
    int cantidadHijos;
    cout << "Cuantos hijos tiene el nodo " << nodo->dato << "? ";
    cin >> cantidadHijos;
    for (int i = 0; i < cantidadHijos; i++) {
        int valor;
        cout << "Ingrese el valor del hijo " << i + 1 << " de " << nodo->dato << ": ";
        cin >> valor;
        Nodo* nuevo = AgregarHijo(nodo, valor);
        ConstruirArbol(nuevo); // Ahora pedimos los hijos del nuevo nodo
    }
}

// Busca un nodo por su valor (recorrido en preorden)
Nodo* BuscarNodo(Nodo* nodo, int valor) {
    if (nodo == nullptr) return nullptr;
    if (nodo->dato == valor) return nodo;
    Nodo* actual = nodo->hijo;
    while (actual != nullptr) {
        Nodo* encontrado = BuscarNodo(actual, valor);
        if (encontrado != nullptr) return encontrado;
        actual = actual->hermano;
    }
    return nullptr;
}

// Una hoja es un nodo que no tiene hijos
void MostrarHojas(Nodo* nodo, int& contador) {
    if (nodo == nullptr) return;
    if (nodo->hijo == nullptr) {
        cout << nodo->dato << "  (Direccion: " << nodo << ")" << endl;
        contador++;
    }
    Nodo* actual = nodo->hijo;
    while (actual != nullptr) {
        MostrarHojas(actual, contador);
        actual = actual->hermano;
    }
}

// Recorrido en preorden: primero el nodo, luego sus hijos
void ImprimirArbol(Nodo* nodo, int nivel) {
    if (nodo == nullptr) return;
    for (int i = 0; i < nivel; i++) {
        cout << "    "; // Sangria segun el nivel
    }
    cout << nodo->dato << "  (Direccion: " << nodo << ")" << endl;
    Nodo* actual = nodo->hijo;
    while (actual != nullptr) {     // Recorremos la lista de hijos
        ImprimirArbol(actual, nivel + 1);
        actual = actual->hermano;
    }
}

// Recorrido en postorden: primero se borran los hijos, luego el padre
void BorrarArbol(Nodo* nodo, int& contador) {
    if (nodo == nullptr) return;
    Nodo* actual = nodo->hijo;
    while (actual != nullptr) {
        Nodo* siguiente = actual->hermano; // Guardar antes de borrar
        BorrarArbol(actual, contador);
        actual = siguiente;
    }
    cout << "Elemento borrado " << contador
        << " | Dato: " << nodo->dato
        << " | Direccion: " << nodo << endl;
    contador++;
    delete nodo;
}

int main()
{
    Nodo* raiz = nullptr; // Declaracion del puntero inicial
    int opc;

    cout << "Actividad 12 - Arbol General\n" << endl;
    do
    {
        cout << "\n_____Menu Principal_____" << endl;
        cout << "1. Ingresar elementos_____" << endl;
        cout << "2. Mostrar hojas__________" << endl;
        cout << "3. Visualizar arbol_______" << endl;
        cout << "0. Salir__________________" << endl;
        cout << "==========================" << endl;
        cout << "ingrese una opcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1: {
            if (raiz == nullptr) {
                // Arbol vacio: primero se crea la raiz
                int valorRaiz;
                cout << "Ingrese el valor de la raiz: ";
                cin >> valorRaiz;
                raiz = CrearNodo(valorRaiz);
                ConstruirArbol(raiz);
            }
            else {
                // Arbol existente: se agregan hijos a un nodo que ya existe
                int valorPadre;
                cout << "Ingrese el valor del nodo padre: ";
                cin >> valorPadre;
                Nodo* padre = BuscarNodo(raiz, valorPadre);
                if (padre == nullptr) {
                    cout << "El nodo " << valorPadre << " no existe en el arbol" << endl;
                }
                else {
                    int cantidad;
                    cout << "Cuantos hijos nuevos tendra el nodo " << padre->dato << "? ";
                    cin >> cantidad;
                    for (int i = 0; i < cantidad; i++) {
                        int valor;
                        cout << "Ingrese el valor del hijo nuevo " << i + 1 << ": ";
                        cin >> valor;
                        Nodo* nuevo = AgregarHijo(padre, valor);
                        ConstruirArbol(nuevo);
                    }
                }
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

            cout << "Arbol (preorden):" << endl;
            ImprimirArbol(raiz, 0);
            break;
        }
        case 0: {
            cout << "Borrando arbol antes de salir:" << endl;
            int contador = 1;
            BorrarArbol(raiz, contador);
            raiz = nullptr;
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
