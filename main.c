#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    struct Libro libros[20] = {0};
    int opcion, i = 0, contadorID = 1;

    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                if (i < 20) {
                    registrarLibro(libros, i, &contadorID);
                    i++;
                } else {
                    printf("Limite de libros alcanzado.\n");
                }
                break;
            case 2:
                mostrarLibros(libros);
                break;
            case 3: {
                int id;
                printf("Ingrese el ID del libro a buscar: ");
                scanf("%d", &id);
                buscarLibroId(libros, id);
                break;
            }
            case 4: {
                char titulo[100];
                printf("Ingrese el titulo del libro a buscar: ");
                getchar();
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
                eliminarLibro(libros, &i);
                break;
            case 7:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion inválida. Por favor, ingrese una opcion valida.\n");
                break;
        }
    } while (opcion != 7);

    return 0;
}
