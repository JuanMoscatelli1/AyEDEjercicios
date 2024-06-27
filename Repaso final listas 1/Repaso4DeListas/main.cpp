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
    cout<<endl;
    return;
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

int cantNodos(nodoListaSE *lista)
{
    int cont =0;
    while(lista)
    {
        cont++;
        lista=obtenerSiguiente(lista);
    }
    return cont;
}

nodoListaSE* buscarAnterior(nodoListaSE * raiz, nodoListaSE * anterior_a)
{
    nodoListaSE *p =NULL;
    if (raiz != anterior_a)
    {
        p = raiz;
        while (p && (p->sgte!= anterior_a) )
        {
            p = p->sgte;
        }
        return p;
    }
    else
        return NULL;
}

void burbuja(nodoListaSE *&lista)
{
    int n,i,j;
    nodoListaSE *aux;
    nodoListaSE *anterior;
    nodoListaSE *proximo;
    bool inter; //Para ver si hubo intercambio  o no
    n= cantNodos(lista);
    for (i=0;i<=n-2;i++)
    {
        aux= lista;//Arranca desde el principio
        for (j=0;j<=n-2-i;j++)
        {
            if (aux->sgte->info < aux->info)
            {
                inter= true;
                if (aux==lista)
                {
                    lista= aux->sgte;
                    proximo= lista->sgte;
                    lista->sgte=aux;
                    aux->sgte=proximo;
                }
                else
                {
                    anterior=buscarAnterior(lista,aux);
                    proximo=aux->sgte;
                    anterior->sgte= proximo;
                    aux->sgte= proximo->sgte;
                    proximo->sgte= aux;
                }
            }
            else
                inter=false;
            if (!inter)
            {
                aux= aux->sgte;
            }
        }
    }
    return;
}


int main()
{
    nodoListaSE *lista = NULL;
    insertarAlFinal(lista,3);
    insertarAlFinal(lista,6);
    insertarAlFinal(lista,4);
    insertarAlFinal(lista,9);
    insertarAlFinal(lista,1);
    cout<<"Lista:"<<endl;
    mostrarLista(lista);
    cout<<"hola??"<<endl;
    getch();
    burbuja(lista);

    cout<<"Lista despues del burbujeo:"<<endl;
    mostrarLista(lista);

    return 0;
}
