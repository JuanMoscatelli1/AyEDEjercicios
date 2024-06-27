#include <iostream>
#include <conio.h>
using namespace std;

struct nodoListaSE
{
    int info;
    nodoListaSE *sgte;
};

nodoListaSE *obtenerSiguiente(nodoListaSE *lista)
{
    if(lista)
    {
        return lista->sgte;
    }else
        return NULL;
}

nodoListaSE *obtenerUltimo(nodoListaSE *lista)
{
    if(lista)
    {
        while(lista->sgte)
        {
            lista=lista->sgte;
        }
    }
    return lista;
}

void mostrarLista(nodoListaSE *lista)
{
    while(lista)
    {
        cout<<lista->info<<" | ";
        lista=obtenerSiguiente(lista);
    }
}

void insertarSiguiente(nodoListaSE *&lista,int num)
{
    nodoListaSE *nuevo = new nodoListaSE();
    nuevo->info = num;
    if(lista!=NULL)
    {
        nuevo->sgte = lista->sgte;
        lista->sgte=nuevo;
    }else
    {
        nuevo->sgte=lista;
        lista=nuevo;
    }
    return;
}

void insertarAlFinal(nodoListaSE *&lista,int num)
{
    nodoListaSE *nuevo = new nodoListaSE();
    nodoListaSE *aux =NULL;
    nuevo->info = num;
    nuevo->sgte = NULL;
    if(lista!=NULL)
    {
        aux=obtenerUltimo(lista);
        aux->sgte = nuevo;
    }else
    {
        lista=nuevo;
    }
}

void intercalar(nodoListaSE *lista1,nodoListaSE *lista2,nodoListaSE *&lista3)
{
    while(lista1)
    {
        insertarAlFinal(lista3,lista1->info);
        if(lista2)
        {
            insertarAlFinal(lista3,lista2->info);
            lista2=lista2->sgte;
        }
        lista1 =lista1->sgte;
    }
    while(lista2)
    {
        insertarAlFinal(lista3,lista2->info);
        lista2=lista2->sgte;
    }
    return;
}


int main()
{
    nodoListaSE *lista1 =NULL;
    nodoListaSE *lista2 =NULL;
    nodoListaSE *lista3 =NULL;

    insertarAlFinal(lista1,3);
    insertarAlFinal(lista1,5);
    insertarAlFinal(lista1,7);
    cout<<"Lista 1: "<<endl;
    mostrarLista(lista1);
    cout<<"Lista 2: "<<endl;
    insertarAlFinal(lista2,45);
    insertarAlFinal(lista2,46);
    insertarAlFinal(lista2,47);
    insertarAlFinal(lista2,48);
    mostrarLista(lista2);
    intercalar(lista1,lista2,lista3);
    cout<<"Lista 3: "<<endl;
    mostrarLista(lista3);
    return 0;
}
