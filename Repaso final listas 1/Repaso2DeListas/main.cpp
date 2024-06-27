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


int main()
{
    nodoListaSE *lista1 =NULL;
    nodoListaSE *lista2 =NULL;
    nodoListaSE *aux=NULL;
    cout<<"Lista 1:"<<endl;
    insertarSiguiente(lista1,3);
    aux=obtenerUltimo(lista1);
    insertarSiguiente(aux,5);
    mostrarLista(lista1);
    cout<<endl;
    cout<<"Lista 2:"<<endl;
    insertarSiguiente(lista2,6);
    aux=obtenerUltimo(lista2);
    insertarSiguiente(aux,8);
    mostrarLista(lista2);
    cout<<endl;
    cout<<"Lista concatenada:"<<endl;
    aux=obtenerUltimo(lista1);
    aux->sgte=lista2;
    mostrarLista(lista1);
    cout<<endl;
    cout<<"Lista 1 desconcatenada:"<<endl;
    aux=lista1;
    while(aux->sgte!=lista2)
    {
        aux=obtenerSiguiente(aux);
    }
    aux->sgte =NULL;
    mostrarLista(lista1);
    cout<<endl;
    cout<<"Lista 2:"<<endl;
    mostrarLista(lista2);


    return 0;
}
