def suma_recursiva(n: int) -> int:
    if n <= 9:
        return n
    return suma_recursiva(n // 10) + n % 10


def suma_iterativa(n: int) -> int:
    suma = 0
    while n > 0:
        suma += n % 10
        n //= 10
    return suma


def leer_entero(mensaje: str, minimo: int) -> int:
    while True:
        try:
            valor = int(input(mensaje))
            if valor >= minimo:
                return valor
        except ValueError:
            pass
        print(f"Entrada inválida. Debe ser un entero >= {minimo}.")


def main() -> None:
    cantidad = leer_entero("¿Cuántos números va a ingresar? ", 1)

    for i in range(1, cantidad + 1):
        n = leer_entero(f"Número {i} (natural): ", 0)
        print(f"  Suma de dígitos (recursiva): {suma_recursiva(n)}")
        print(f"  Suma de dígitos (iterativa): {suma_iterativa(n)}")


if __name__ == "__main__":
    main()
