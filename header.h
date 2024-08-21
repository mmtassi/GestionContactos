#ifndef HEADER_H
#define HEADER_H

typedef  struct contacto {
    char nombre[15];
    char *numero;
    int edad;
    struct contacto* sig;
}Contacto;

typedef struct lista {
    int cantidad;
    Contacto* cab;
}ListaContactos;

Contacto* newContacto(char *nombre, char *numero, int edad);
ListaContactos* newLista();
void agregarContacto(ListaContactos* lista, Contacto* contacto);
void imprimir(ListaContactos* lista);

#endif //HEADER_H
