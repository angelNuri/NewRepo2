# include <iostream>
# include <string>
using namespace std;

int main() {
	string aves[10] = { "Paloma","tortolita","Pollo" };
	int cantidad = 3;
	int posicion;
	string nueva;
	cout << "Acves actuales:" << endl;
	for(int i = 0; i < cantidad; i++)
		cout <<i+1<<". "<<aves[i]<<endl;
	cout << "posicion de la ave nueva";
	cin >> posicion;
	cout << " ave nueva: ";
		cin >> nueva;
    for (int i = cantidad; i >= posicion; i--)
			aves[i] = aves[i - 1];
    aves[posicion - 1] = nueva;
    cantidad++;
    cout << "\nArreglo final:" << endl;
	for (int i = 0; i < cantidad; i++)
		cout << i + 1 << ". " << aves[i] << endl;

		return 0;
}
