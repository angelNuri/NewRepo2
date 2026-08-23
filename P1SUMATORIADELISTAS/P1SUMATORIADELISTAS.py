# Encabezado
numero_global = 8

# Funciones secundarias
def sumatoria(numero_local):
    arreglo_numeros = [0] * numero_global
    resultado = 0

    for i in range(numero_local):
        arreglo_numeros[i] = int(input("Ingrese el valor de la posición: "))
        resultado = resultado + arreglo_numeros[i]

    return resultado


# Función principal
def main():
    print("Actividad 02 - Sumatoria acumulativa memoria estática")
    resultado = sumatoria(numero_global)
    print("El resultado de la sumatoria es igual a:", resultado)


if __name__ == "__main__":
    main()