#include <iostream>

using namespace std;
#define MaxTamC 10 /// Tamaño maximo de la cola

typedef int TipoDato;

void ingresar_valores( int &frente, int &final, TipoDato A[], int &contador) {
    if ((final + 1) % MaxTamC == frente) {
        cout << "Desbordamiento de la cola" << endl;
        return ;
    }

    cout << "Ingrese un elemento para la cola: ";
    TipoDato elemento;
    cin >> elemento;

    final = (final + 1) % MaxTamC;
    A[final] = elemento;

    contador++;
    cout << "Elemento " << contador << " agregado a la cola: " << elemento << endl;
}

void eliminar_elemento(int &frente, int final, int &contador) {
    if (frente == final) {
        cout << "La cola esta vacia, no se puede eliminar" << endl;
        return;
    }
    frente = (frente + 1) % MaxTamC;
    contador--;
    cout << "Elemento eliminado de la cola." << endl;
}

void imprimir(int &frente, int &final, TipoDato A[]) {

    cout << "Elementos de la cola en el orden de ingreso:" << std::endl;
    for (int i = frente + 1; i <= final; i = (i + 1) % MaxTamC) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {

    TipoDato A[MaxTamC];
    int contador = 0;

    int frente = 0;
    int final = 0;

    cout << "Desea agregar elementos a la cola? (s/n): ";
    char respuesta;
    cin >> respuesta;
    while ((respuesta == 's' || respuesta == 'S') && contador < 10) {
        ingresar_valores(frente, final, A, contador);

        if (contador < 10) {
            cout << "Desea agregar mas elementos a la cola? (s/n): ";
            cin >> respuesta;
        }
    }

    if (frente == final) {
        cout << "La cola esta vacia." << endl;
        return 1;
    }
    TipoDato primerElemento = A[(frente + 1) % MaxTamC];
    cout << "El primer elemento de la cola es: " << primerElemento << endl;
    eliminar_elemento(frente, final, contador);
    imprimir(frente, final,A);

    return 0;
}
