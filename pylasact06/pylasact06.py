capacidad = 5
pila = []

print("Apilar")
while True:
    try:
        if len(pila) >= capacidad:
            raise Exception("La pila se lllenó")

        valor = int(input("Ingrese un número:"))
        pila.append(valor)
    except Exception as mensaje:
        print(mensaje)
        break  
print("\nPILA")
for elemento in pila:
    print(elemento, end=" ")
print()
print("Despapilar")
while True:
    try:
        if len(pila) == 0:
            raise Exception("vacío")

        print("Quitar pila numero; ", pila[-1])
        pila.pop()
    except Exception as mensaje:
        print(mensaje)
        break 
