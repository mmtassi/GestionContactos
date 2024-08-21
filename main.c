#include <stdio.h>

#include "header.h"

int main() {
    ListaContactos* lista=newLista();
    agregarContacto(lista,newContacto("d","1134052474",31));
    agregarContacto(lista,newContacto("c","1134052474",22));
    agregarContacto(lista,newContacto("b","1155433474",14));
    agregarContacto(lista,newContacto("a","1155555474",29));
    imprimir(lista);
    return 0;
}
