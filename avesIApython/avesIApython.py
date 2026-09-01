"""
Ejercicio: arreglo de tamaño fijo (capacidad máxima) con inserción de
elementos en una posición arbitraria.

Se simula un arreglo estático usando una lista de Python pre-asignada con
`None`, separando la CAPACIDAD (tamaño físico reservado) del TAMAÑO ACTUAL
(cantidad de posiciones realmente ocupadas), tal como ocurriría en un
arreglo de tamaño fijo en C o Java.
"""

from typing import List, Optional

CAPACIDAD_MAXIMA: int = 10


def crear_arreglo(capacidad: int) -> List[Optional[str]]:
    """Crea un arreglo de tamaño fijo `capacidad`, con todas sus
    posiciones inicializadas en None (celdas vacías)."""
    return [None] * capacidad


def cargar_datos_iniciales(arreglo: List[Optional[str]], datos: List[str]) -> int:
    """Coloca los `datos` iniciales dentro del arreglo pre-asignado.
    Devuelve el tamaño lógico inicial (cantidad de elementos cargados)."""
    if len(datos) > len(arreglo):
        raise ValueError("Los datos iniciales exceden la capacidad del arreglo.")
    for indice, valor in enumerate(datos):
        arreglo[indice] = valor
    return len(datos)


def mostrar_arreglo(arreglo: List[Optional[str]], tamanio_actual: int, titulo: str) -> None:
    """Imprime únicamente las posiciones actualmente ocupadas del arreglo."""
    print(titulo)
    if tamanio_actual == 0:
        print("  (vacío)")
        return
    for i in range(tamanio_actual):
        print(f"{i + 1}. {arreglo[i]}")


def pedir_entero(mensaje: str) -> int:
    """Pide un número entero por consola. Repite la solicitud si el
    usuario ingresa algo que no se pueda convertir a int, evitando que
    el programa se caiga con ValueError."""
    while True:
        entrada = input(mensaje)
        try:
            return int(entrada)
        except ValueError:
            print(f"Error: '{entrada}' no es un número entero válido. Intente de nuevo.")


def insertar_en_posicion(
    arreglo: List[Optional[str]],
    tamanio_actual: int,
    posicion: int,
    elemento: str,
) -> int:
    """Inserta `elemento` en `posicion` (1-indexada), recorriendo los
    elementos existentes una casilla a la derecha para hacer espacio.
    Devuelve el nuevo tamaño lógico del arreglo.

    Lanza IndexError si el arreglo está lleno, o ValueError si la
    posición está fuera del rango permitido.
    """
    capacidad = len(arreglo)

    if tamanio_actual >= capacidad:
        raise IndexError("el arreglo está lleno, no se pueden agregar más elementos")

    if posicion < 1 or posicion > tamanio_actual + 1:
        raise ValueError(f"debe estar entre 1 y {tamanio_actual + 1}")

    indice = posicion - 1
    for i in range(tamanio_actual, indice, -1):
        arreglo[i] = arreglo[i - 1]
    arreglo[indice] = elemento

    return tamanio_actual + 1


def main() -> None:
    """Orquesta el flujo del ejercicio: carga datos, muestra el arreglo,
    pide una posición y un ave nueva, e inserta si es válido."""
    aves = crear_arreglo(CAPACIDAD_MAXIMA)
    tamanio_actual = cargar_datos_iniciales(aves, ["Tucan", "Guacamaya", "Gallina"])

    mostrar_arreglo(aves, tamanio_actual, "Arreglo original:")

    pos = pedir_entero("Ingrese la posicion: ")
    nueva_ave = input("Nueva ave: ").strip()

    if not nueva_ave:
        print("El nombre del ave no puede estar vacío.")
        return

    try:
        tamanio_actual = insertar_en_posicion(aves, tamanio_actual, pos, nueva_ave)
    except IndexError as error:
        print(f"Estamos llenos ({error}).")
    except ValueError as error:
        print(f"No se puede: {error}.")
    else:
        mostrar_arreglo(aves, tamanio_actual, "Arreglo despues de la insercion:")


if __name__ == "__main__":
    main()
