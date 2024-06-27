#include <iostream>
#include <conio.h>

using namespace std;

struct nodoListaSE
{
    int info;
    nodoListaSE *sgte;
};

void insertarOrdenado(nodoListaSE *&lista,int aInsertar)
{
    nodoListaSE *paux=lista;
    nodoListaSE *anterior=NULL;
    while(paux && paux->info<aInsertar)
    {
        anterior=paux;
        paux=paux->sgte;
    }
    if(paux!=lista)
    {
        anterior->sgte=new nodoListaSE();
        anterior->sgte->info=aInsertar;
        anterior->sgte->sgte=paux;
    }
    else
    {
        lista=new nodoListaSE();
        lista->info=aInsertar;
        lista->sgte=paux;
    }
    return;
}

void mostrarLista(nodoListaSE *lista)
{
    while(lista)
    {
        cout<<lista->info<<"|"<<endl;
        lista=lista->sgte;
    }
    return;
}

int main()
{
    nodoListaSE *lista=NULL;
    insertarOrdenado(lista,15);
    insertarOrdenado(lista,20);
    insertarOrdenado(lista,18);
    insertarOrdenado(lista,10);
    mostrarLista(lista);

    return 0;
}
