#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Contacto * newContacto(char *nombre, char *numero, int edad) {
    Contacto* aux=malloc(sizeof(Contacto));
    if (aux == NULL) {
        printf("No hay memoria disponible");
        exit(-1);
    }
    strcpy(aux->nombre,nombre);
    aux->numero=numero;
    aux->edad=edad;
    aux->sig=NULL;
    return aux;
}

ListaContactos * newLista() {
    ListaContactos* aux=malloc(sizeof(ListaContactos));
    if (aux == NULL) {
        printf("No hay memoria disponible");
        exit(-1);
    }
    aux->cantidad=0;
    aux->cab=NULL;
    return aux;
}

void agregarContacto(ListaContactos *lista, Contacto *contacto) {
    char *nombre=contacto->nombre;
    if(nombre[0] >96) {
        nombre[0]=nombre[0] - 32;
    }
    if(lista->cab == NULL) {
        lista->cab=contacto;
        lista->cantidad++;
    }else {
        Contacto* aux=lista->cab;
        if (aux->sig == NULL && aux->nombre[0] < nombre[0]) {
            aux->sig=contacto;
            lista->cantidad++;
        }else if(aux->nombre[0] > nombre[0]) {
            contacto->sig=lista->cab;
            lista->cab=contacto;
            lista->cantidad++;
        }else{
            while(aux->sig != NULL && aux->sig->nombre[0] < nombre[0]) {
                aux=aux->sig;
            }
            contacto->sig=aux->sig;
            aux->sig=contacto;
            lista->cantidad++;
        }
    }
}

Contacto *buscarContacto(ListaContactos *lista, char *contacto) {
    Contacto* aux=lista->cab;
    //if(contacto[0] >96) {
    //    contacto[0]=contacto[0] - 32;
    //}
    while (aux != NULL) {
        if(strcmp(aux->nombre,contacto) == 0) {
            return aux;
        }
        aux=aux->sig;
    }
    return NULL;
}

void imprimirContacto(ListaContactos *lista, char *contacto) {
    Contacto* aux=buscarContacto(lista,contacto);
    //if(contacto[0] > 96) {
    //    contacto[0]=contacto[0] - 32;
    //}
    while (aux != NULL) {
        if(strcmp(aux->nombre,contacto) == 0) {
            printf("Nombre: %s\nEdad: %i\nTelefono: %s",aux->nombre,aux->edad,aux->numero);
            return;
        }
        aux=aux->sig;
    }
    printf("El contacto no existe");
}



void imprimir(ListaContactos *lista) {
    Contacto* aux=lista->cab;
    if(aux == NULL) {
        printf("No hay contactos");
    }else {
        while (aux != NULL) {
            printf("Nombre: %s\nEdad: %i\nNumero de telefono: %s\n\n",aux->nombre,aux->edad,aux->numero);
            aux=aux->sig;
        }
        printf("Cantidad de contactos: %i",lista->cantidad);
    }
}
