#include <iostream>
#include <conio.h>
using namespace std;

struct nodoListaSE
{
    int info;
    nodoListaSE *sgte;
};

nodoListaSE *obtenerSiguiente(nodoListaSE *n)
{
    if(n)
        return n->sgte;
    else
        return NULL;
}

nodoListaSE* buscarNodoAnterior(nodoListaSE *n,nodoListaSE *anteriorA)
{
    nodoListaSE *elAnterior = NULL;
    if(n != anteriorA)
    {
        elAnterior = n;
        while(elAnterior && (elAnterior->sgte != anteriorA))
        {
            elAnterior = elAnterior->sgte;
        }
        return elAnterior;
    }else
        return NULL;

}

void insertarSiguiente(nodoListaSE *&n,int numero)
{
    nodoListaSE *aInsertar = new nodoListaSE();
    aInsertar->info = numero;
    if (n!=NULL)
    {
        aInsertar->sgte = n->sgte;
        n->sgte = aInsertar;
    }
    else
    {
        aInsertar->sgte = n;
        n=aInsertar;
    }
    return;
}

nodoListaSE *obtenerUltimo(nodoListaSE *copiaLista)
{
    if(copiaLista)
    {
        while(copiaLista->sgte)
        {
            copiaLista=copiaLista->sgte;
        }
    }
    return copiaLista;
}

void insertarAlFinal(nodoListaSE *&n,int numero)
{
    nodoListaSE *aInsertar = new nodoListaSE();
    nodoListaSE *ultimo = NULL;
    aInsertar->info = numero;
    aInsertar->sgte = NULL;
    if(n!=NULL)
    {
        ultimo = obtenerUltimo(n);
        ultimo->sgte = aInsertar;
    }else
    {
        n=aInsertar;
    }
    return;
}

void insertarPrimero(nodoListaSE *&lista,int numero)
{
    nodoListaSE *aInsertar = new nodoListaSE();
    nodoListaSE *aux = lista;
    aInsertar->info=numero;
    lista=aInsertar;
    aInsertar->sgte = aux;
    return;
}

void insertarOrdenado(nodoListaSE *&lista, int numero)
    {
       nodoListaSE *anterior = NULL;
       nodoListaSE *aux = lista;
       while( aux && aux->info<numero)
       {
           aux = aux->sgte;
       }

       if(aux && aux!=lista)
       {
           anterior = buscarNodoAnterior(lista,aux);
           insertarSiguiente(anterior,numero);

       }else
       {
        if(aux=NULL)
        {
           insertarAlFinal(lista,numero);
        }else
        {
          if (aux==lista)
            {
            insertarPrimero(lista,numero);
            }
        }

       }
        return;

    }

void mostrarLista(nodoListaSE *lista)
{
    while(lista)
    {
        cout<<lista->info<<" | "<<endl;
        lista=obtenerSiguiente(lista);
    }
    cout<<endl;
}


char mostrarMenuYDevolver()
{
    cout<<"Presione 1 para mostrar la lista"<<endl;
    cout<<"Presione 2 para insertar ordenadamente"<<endl;
    cout<<"Presione 3 para buscar el mayor elemento"<<endl;
    cout<<"Presione 4 para calcular el promedio"<<endl;
    cout<<"esc para salir"<<endl;
    char opcion;
    do{
        opcion=getch();
    }while((opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4') && (opcion!=27));
    return opcion;
}

int main()
{
    char elegida;
    int numeroIngresado;
    nodoListaSE *lista = NULL;
    nodoListaSE *aux = NULL;
    do
        {
        elegida = mostrarMenuYDevolver();
        switch(elegida)
        {
        case '1':
            mostrarLista(lista);

            break;

        case '2':

                cout<<"Ingrese un numero para insertar"<<endl;
                cin>> numeroIngresado;
                insertarOrdenado(lista,numeroIngresado);
            break;
        case '3':
           aux = lista;
           while(aux && aux->sgte)
           {
               aux= obtenerSiguiente(aux);
           }
           if(aux)
           {
               cout<<"El mayor es: "<< aux->info<<endl;
           }else
           {
               cout<<"Lista vacia"<<endl;
           }
           break;

        }
    getch();
    }while(elegida!=27);
    return 0;
}
