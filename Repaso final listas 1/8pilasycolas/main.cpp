#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>

#define VACIO -1000
using namespace std;

struct nodoLista
{
    int info;
    nodoLista *sgte;
};

void insertarSiguienteSE(nodoLista *&lista,int numero)
{
    nodoLista *nuevo = new nodoLista();
    nuevo->info = numero;
    if(lista)
    {
        nuevo->sgte=lista->sgte;
        lista->sgte = nuevo;
    }else
    {
        nuevo->sgte=lista;
        lista=nuevo;
    }
    return;
}

void insertarAlFinalSE(nodoLista *&lista,int numero)
{
    nodoLista *aux=lista;
    while(aux && aux->sgte)
        {
            aux = aux->sgte;
        }
    if(aux)
    {
        insertarSiguienteSE(aux,numero);
    }else
        {
           insertarSiguienteSE(lista,numero);
        }

        return;
}

int desencolar(nodoLista *&cola)
{
    nodoLista *aux;
    int numero;
    if(cola)
    {
        aux=cola;
        numero=cola->info;
        cola=aux->sgte;
        delete aux;
        return numero;
    }else
    return VACIO;
}

nodoLista *buscarAnterior(nodoLista *lista,nodoLista *anteriorAEste)
{
    nodoLista *aux =NULL;
    if(lista!=anteriorAEste)
    {
        aux = lista;
        while(aux && aux->sgte!=anteriorAEste)
        {
            aux=aux->sgte;
        }
        return aux;
    }else
        return NULL;
}

void borrarSiguiente(nodoLista *&lista)
{
    nodoLista *aBorrar = lista->sgte;
    nodoLista *sgteABorrar ;
    if(aBorrar)
    {
        sgteABorrar =aBorrar->sgte;
    }else
    {
        sgteABorrar =NULL;
    }
    lista->sgte= sgteABorrar;
    delete aBorrar;
    return;
}

void borrarNodo(nodoLista *&lista,nodoLista *&aBorrar)
{
    if(lista && aBorrar)
    {
        if(aBorrar==lista)
        {
            lista=lista->sgte;
            delete aBorrar;
        }
        else
        {
            nodoLista *ant = buscarAnterior(lista,aBorrar);
            borrarSiguiente(ant);

        }
    }
    return;
}

int desapilar(nodoLista *&pila)
{
    nodoLista *aux=pila;
    int numero;
    while(aux->sgte)
    {
        aux=aux->sgte;
    }
    if(aux)
    {
        numero=aux->info;
        borrarNodo(pila,aux);
        return numero;
    }else
    {
        return VACIO;
    }
}

void borrarLista(nodoLista *&lista)
{
    nodoLista *aux;
    nodoLista *anterior;
    while(lista!=NULL)
    {
        anterior=NULL;
        aux = lista;
        while(aux && aux->sgte)
        {
            anterior=aux;
            aux=aux->sgte;
        }
        if(aux)
        {
            delete(aux);
            if(anterior!=NULL)
            {
                anterior->sgte=NULL;
            }else
            {
                lista=NULL;
            }
        }
    }
    return;
}

int main()
{
    nodoLista *cola=NULL;

    insertarAlFinalSE(cola,3);
    insertarAlFinalSE(cola,4);
    insertarAlFinalSE(cola,3);
    nodoLista *esUnaPila=NULL;
    insertarAlFinalSE(esUnaPila,3);
    insertarAlFinalSE(esUnaPila,4);
    insertarAlFinalSE(esUnaPila,3);
    int cant=0;
    int noSonIguales=0;

    nodoLista *aux =cola;

    while(aux->sgte)
    {
       cant++;
       aux=aux->sgte;
    }

    int numCola=0;
    int numPila=0;
    for(int i=0;i<cant-1;i++)
    {
        numPila=desapilar(esUnaPila);
        numCola=desencolar(cola);
        if(numPila!=numCola)
        {
            noSonIguales=1;
        }
    }

    if(!noSonIguales)
    {
        cout<<"es capicua :)"<<endl;
    }
    borrarLista(cola);
    borrarLista(esUnaPila);
    return 0;
}
