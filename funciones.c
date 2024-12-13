#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu() {
    int opcion;
    printf("\n MENU \n");
    printf("1. Registrar libro\n");
    printf("2. Mostrar listado de libros\n");
    printf("3. Buscar libro por ID\n");
    printf("4. Buscar libro por titulo\n");
    printf("5. Actualizar estado del libro\n");
    printf("6. Eliminar libro\n");
    printf("7. Salir\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void registrarLibro(struct Libro libros[], int indice, int *contadorID) {
    if (indice < 20) {
        libros[indice].id = (*contadorID)++;
        printf("\nIngrese el titulo del libro: ");
        getchar();
        fgets(libros[indice].titulo, 100, stdin);
        libros[indice].titulo[strcspn(libros[indice].titulo, "\n")] = 0;

        printf("Ingrese el autor del libro: ");
        fgets(libros[indice].autor, 50, stdin);
        libros[indice].autor[strcspn(libros[indice].autor, "\n")] = 0;

        do {
            printf("Ingrese el anio de publicacion del libro: ");
            scanf("%d", &libros[indice].anio);
            if (libros[indice].anio < 0 || libros[indice].anio > 2024) {
                printf("Anio no valido. Intente de nuevo.\n");
            }
        } while (libros[indice].anio < 0 || libros[indice].anio > 2024);

        strcpy(libros[indice].estado, "Disponible");
        printf("\nLibro registrado. ID: %d\n", libros[indice].id);
    } else {
        printf("\nNo se pueden agregar mas libros. Limite alcanzado.\n");
    }
}

void mostrarLibros(struct Libro libros[]) {
    printf("\n%-5s%-30s%-20s%-10s%-15s\n", "ID", "Titulo", "Autor", "Anio", "Estado");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < 20; i++) {
        if (libros[i].id != 0) {
            printf("%-5d%-30s%-20s%-10d%-15s\n",
                   libros[i].id,
                   libros[i].titulo,
                   libros[i].autor,
                   libros[i].anio,
                   libros[i].estado);
        }
    }
}

void buscarLibroId(struct Libro libros[], int id) {
    for (int i = 0; i < 20; i++) {
        if (libros[i].id == id) {
            printf("\nLibro encontrado:\n");
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor,
                   libros[i].anio, libros[i].estado);
            return;
        }
    }
    printf("\nLibro no encontrado.\n");
}

void buscarLibroTitulo(struct Libro libros[], char titulo[]) {
    for (int i = 0; i < 20; i++) {
        if (strcmp(libros[i].titulo, titulo) == 0) {
            printf("\nLibro encontrado:\n");
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor,
                   libros[i].anio, libros[i].estado);
            return;
        }
    }
    printf("\nLibro no encontrado.\n");
}

void actualizarEstado(struct Libro libros[], int id) {
    char nuevoEstado[50];

    for (int i = 0; i < 20; i++) {
        if (libros[i].id == id) {
            printf("Ingrese el nuevo estado del libro (Disponible / Prestado): ");
            getchar();
            fgets(nuevoEstado, 50, stdin);
            nuevoEstado[strcspn(nuevoEstado, "\n")] = 0;

            if (strcmp(nuevoEstado, "Disponible") == 0 || strcmp(nuevoEstado, "Prestado") == 0) {
                strcpy(libros[i].estado, nuevoEstado);
                printf("\nEstado actualizado. Nuevo estado: %s\n", libros[i].estado);
            } else {
                printf("\nEstado no valido. El estado debe ser 'Disponible' o 'Prestado'.\n");
            }
            return;
        }
    }
    printf("\nLibro no encontrado.\n");
}

void eliminarLibro(struct Libro libros[], int *i) {
    int id;
    printf("\nIngrese el ID del libro a eliminar: ");
    scanf("%d", &id);

    for (int j = 0; j < 20; j++) {
        if (libros[j].id == id) {
            printf("¿Esta seguro de que desea eliminar este libro? (1. Si / 2. No): ");
            int confirmar;
            scanf("%d", &confirmar);
            if (confirmar == 1) {
                for (int k = j; k < (*i) - 1; k++) {
                    libros[k] = libros[k + 1];
                }
                (*i)--;
                libros[*i].id = 0;
                printf("\nLibro eliminado.\n");
            } else if (confirmar == 2) {
                printf("\nOperacion cancelada. El libro no fue eliminado.\n");
            } else {
                printf("\nOpcion no valida. El libro no fue eliminado.\n");
            }
            return;
        }
    }
    printf("\nLibro no encontrado.\n");
}
