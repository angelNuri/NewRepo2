"""
MisGustos TuNombre
Proyecto de Estructura de Datos - Tema: Tecnologias
"""

# ---------------------------------------------------------
# Constantes globales
# ---------------------------------------------------------
NOMBRE_PROYECTO = "MisGustos TuNombre"  # Reemplaza "TuNombre" por tu nombre
TEMA = "Tecnologias"
FILAS = 2
COLUMNAS = 3


def matriz(lista_base):
    """Copia los 6 elementos de la lista base en una matriz de 2x3."""
    mat = []
    indice = 0
    for _ in range(FILAS):
        fila = []
        for _ in range(COLUMNAS):
            fila.append(lista_base[indice])
            indice += 1
        mat.append(fila)
    return mat


def pila(lista_base):
    """
    Transfiere los 6 elementos de la lista base a una pila (lista)
    con append y luego apila 2 tecnologias adicionales.
    """
    p = []

    # Se apilan los 6 elementos iniciales
    for elemento in lista_base:
        p.append(elemento)

    # Se apilan 2 tecnologias adicionales
    p.append("AWS")
    p.append("React")

    return p


def imprimir(mat, p):
    """Muestra la matriz 2x3 formateada y los elementos finales de la pila."""
    print("\n===== CONTENIDO DE LA MATRIZ 2x3 =====")
    if mat:
        for fila in mat:
            for elemento in fila:
                print(f"[{elemento:^10}]", end=" ")
            print()
    else:
        print("La matriz aun no ha sido generada (use la opcion 1).")

    print("\n===== CONTENIDO FINAL DE LA PILA =====")
    if p:
        # Se imprime desde el tope (ultimo elemento) hasta la base
        for i in range(len(p) - 1, -1, -1):
            prefijo = "TOPE -> " if i == len(p) - 1 else "         "
            print(f"{prefijo}{p[i]}")
    else:
        print("La pila aun no ha sido generada (use la opcion 2).")
    print()


def mostrar_menu():
    """Despliega el menu principal."""
    print("======================================")
    print(f"  {NOMBRE_PROYECTO}")
    print(f"  Tema: {TEMA}")
    print("======================================")
    print("1. Generar matriz 2x3")
    print("2. Generar pila (con push de AWS y React)")
    print("3. Imprimir matriz y pila")
    print("4. Salir")


def main():
    """Funcion principal con el ciclo continuo del menu."""
    # Lista base inicial de 6 elementos
    tecnologias = ["Python", "Linux", "Docker", "SQL", "Git", "FastAPI"]

    mat = []
    p = []
    opcion = 0

    while opcion != 4:
        mostrar_menu()

        # Validacion de entrada numerica
        try:
            opcion = int(input("Seleccione una opcion: "))
        except ValueError:
            print("\nEntrada invalida. Ingrese un numero.\n")
            opcion = 0
            continue

        if opcion == 1:
            mat = matriz(tecnologias)
            print("\nMatriz 2x3 generada correctamente.\n")
        elif opcion == 2:
            p = pila(tecnologias)
            print("\nPila generada correctamente (8 elementos).\n")
        elif opcion == 3:
            imprimir(mat, p)
        elif opcion == 4:
            print("\nSaliendo del programa. Hasta luego.")
        else:
            print("\nOpcion no valida. Intente de nuevo.\n")


if __name__ == "__main__":
    main()