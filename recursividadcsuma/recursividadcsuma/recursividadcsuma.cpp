#include <iostream>
using namespace std;

int sumaRecursiva(int n)
{
    if (n <= 9)
        return n;
    else
        return sumaRecursiva(n / 10) + n % 10;
}

int sumaIterativa(int n)
{
    int suma = 0;
    while (n > 0)
    {
        suma = suma + n % 10;
        n = n / 10;
    }
    return suma;
}

int main()
{
    int cantidad, n, i;

    cout << "Cuantos numeros va a ingresar? ";
    cin >> cantidad;

    for (i = 1; i <= cantidad; i++)
    {
        cout << "Numero " << i << ": ";
        cin >> n;

        cout << "Suma de digitos (recursiva): " << sumaRecursiva(n) << endl;
        cout << "Suma de digitos (iterativa): " << sumaIterativa(n) << endl;
    }

    return 0;
}