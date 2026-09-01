#include <iostream>
#include <string>
using namespace std;

int main()
{
	string aves[15];

	int cantidad = 5;
	int posicion;
	string nuevoelemento;

	aves[0] = "Paloma";
	aves[1] = "Tortolita";
	aves[2] = "Guacamaya";
	aves[3] = "Zopilote";
	aves[4] = "Aguila";

	cout << "Arreglo Inicial" << endl;
	for (int i = 0; i < cantidad; i++)
	{
		cout << i + 1 << ". " << aves[i] << endl;
	}

	if (cantidad >= 15)
	{
		cout << "Estamos llenos " << endl;
		return 0;
	}

	cout << "Ingrese la posicion del ave nueva (1 a " << cantidad + 1 << "): ";
	cin >> posicion;
	cout << "Ingrese el nombre de la nueva ave: ";
	cin >> nuevoelemento;

	if (posicion < 1 || posicion > cantidad + 1)
	{
		cout << "Posicion invalida." << endl;
	}
	else
	{
		for (int i = cantidad; i >= posicion; i--)
		{
			aves[i] = aves[i - 1];
		}

		aves[posicion - 1] = nuevoelemento;
		cantidad++;

		cout << "Arreglo final" << endl;
		for (int i = 0; i < cantidad; i++)
		{
			cout << i + 1 << ". " << aves[i] << endl;
		}
	}

	return 0;
}