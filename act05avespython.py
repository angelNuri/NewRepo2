capacidad = 10
aves = ["Tucan","Guacamaya", "Gallina"]
print("Arreglo original:")
for i in range(len(aves)):
    print(i + 1, ".", aves[i])

pos = int(input("Ingrese la posicion: "))
nueva_ave = input("Nueva ave: ")

if len(aves) >= capacidad:
    print("Estamos llenos")

elif pos < 1 or pos > len(aves) + 1:
    print("No se puede")

else:
    aves.insert(pos - 1, nueva_ave)

    print("Arreglo despues de la insercion:")

    for i in range(len(aves)):
        print(i + 1, ".", aves[i])

