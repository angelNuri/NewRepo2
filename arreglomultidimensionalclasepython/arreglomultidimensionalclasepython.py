filas = 3
columnas = 3

def captura_matriz(a):
    for i in range(filas):
        for j in range(columnas):
            a[i][j] = int(input(f"Ingresa el valor para la posición [{i}][{j}]: "))
    return a

def impresion_matriz(arreglo):
    print("Los valores de la matriz son:")
    for a in range(filas):
        for b in range(columnas):
            print(arreglo[a][b], end=" ")
        print()

def main():
    arreglo_bidimensional = [[0 for j in range(columnas)] for i in range(filas)]
    
    print("Actividad 3: Arreglo multidimensional")
    
    arreglo_local = captura_matriz(arreglo_bidimensional)
    impresion_matriz(arreglo_local)

if __name__ == "__main__":
    main()

