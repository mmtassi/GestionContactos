#include <stdio.h>

#include "header.h"

int main() {
    ListaContactos* lista=newLista();
    agregarContacto(lista,newContacto("matias","1134052474",31));
    agregarContacto(lista,newContacto("fabian","1134052474",22));
    agregarContacto(lista,newContacto("thiago","1155433474",14));
    agregarContacto(lista,newContacto("martin","1155555474",29));
    imprimir(lista);
    return 0;
}
