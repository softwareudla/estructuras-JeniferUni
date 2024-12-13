struct Libro {
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[50];
};

int menu();
void registrarLibro(struct Libro libros[], int indice, int *contadorID);
void mostrarLibros(struct Libro libros[]);
void buscarLibroId(struct Libro libros[], int id);
void buscarLibroTitulo(struct Libro libros[], char titulo[]);
void actualizarEstado(struct Libro libros[], int id);
void eliminarLibro(struct Libro libros[], int *i);
