#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    struct Libro libros[20] = {0};
    int opc, count = 0;

    do {
        opc = menu();
        switch (opc) {
            case 1:
                if (count < 20) {
                    registrarLibros(libros, count);
                    count++;
                } else {
                    printf("Limite de libros alcanzado.\n");
                }
                break;
            case 2:
                mostrarLibros(libros);
                break;
            case 3: {
                int id;
                printf("Ingrese el id del libro a buscar: ");
                scanf("%d", &id);
                buscarLibroId(libros, id);
                break;
            }
            case 4: {
                char titulo[100];
                printf("Ingrese el titulo del libro a buscar: ");
                getchar(); // Limpia el buffer
                fgets(titulo, 100, stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                buscarLibroTitulo(libros, titulo);
                break;
            }
            case 5: {
                int id;
                printf("Ingrese el ID del libro para actualizar su estado: ");
                scanf("%d", &id);
                actualizarEstado(libros, id);
                break;
            }
            case 6:
                eliminarLibro(libros, &count);
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, ingrese una opcion valida.\n");
                break;
        }
    } while (opc != 7);

    return 0;
}
