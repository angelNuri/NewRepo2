from typing import List

FILAS = 3
COLUMNAS = 3

Matriz = List[List[int]]


def crear_matriz(filas: int, columnas: int, valor_inicial: int = 0) -> Matriz:
    """Crea una matriz de 'filas' x 'columnas' inicializada con 'valor_inicial'."""
    return [[valor_inicial for _ in range(columnas)] for _ in range(filas)]


def capturar_valor_entero(mensaje: str) -> int:
    """Solicita un entero al usuario, repitiendo la solicitud si la entrada no es valida."""
    while True:
        try:
            return int(input(mensaje))
        except ValueError:
            print("Entrada invalida. Por favor ingresa un numero entero.")


def capturar_matriz(matriz: Matriz) -> Matriz:
    """
    Solicita al usuario los valores de cada posicion de 'matriz' y la modifica in place.
    El tamano se deduce dinamicamente a partir de 'matriz' (no de variables globales),
    por lo que la funcion sirve para matrices de cualquier dimension.
    """
    filas = len(matriz)
    columnas = len(matriz[0]) if filas > 0 else 0

    for i in range(filas):
        for j in range(columnas):
            matriz[i][j] = capturar_valor_entero(
                f"Ingresa el valor para la posicion [{i}][{j}]: "
            )
    return matriz


def imprimir_matriz(matriz: Matriz) -> None:
    """Imprime los valores de 'matriz' fila por fila, deduciendo su tamano dinamicamente."""
    print("Los valores de la matriz son:")
    for fila in matriz:
        print(" ".join(str(valor) for valor in fila))


def main() -> None:
    print("Actividad 3: Arreglo multidimensional")

    matriz = crear_matriz(FILAS, COLUMNAS)
    capturar_matriz(matriz)
    imprimir_matriz(matriz)


if __name__ == "__main__":
    main()
