# Printf

## Descripción

Printf es un proyecto del curso de la Escuela 42 que consiste en recrear la función `printf` de la biblioteca estándar de C. `printf` es una función que formatea y muestra datos en la salida estándar de acuerdo con un formato específico. La tarea es implementar una versión simplificada de esta función, capaz de manejar algunos de los formatos básicos más comunes.

## Características

- Implementación de la función `printf` en C.
- Manejo de formatos de impresión, como `%s`, `%d`, `%c`, etc.
- Soporte para modificadores de longitud, especificadores de precisión y otros flags.

## Requisitos

- Sistema operativo: Linux.
- Compilador compatible con C.

## Instalación

1. Clona este repositorio:
    ```sh
    git clone https://github.com/roallamos/printf.git
    ```
2. Navega al directorio del proyecto:
    ```sh
    cd printf
    ```
3. Compila el proyecto:
    ```sh
    make
    ```

## Uso

1. Incluye el archivo `ft_printf.h` en tus archivos de código fuente.
    ```c
    #include "ft_printf.h"
    ```

2. Llama a la función `ft_printf` para formatear y mostrar datos en la salida estándar.
    ```c
    int ft_printf(const char *format, ...);
    ```

## Ejemplo de Uso

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("The value of pi is approximately %.2f.\n", 3.14159);
    return (0);
}
