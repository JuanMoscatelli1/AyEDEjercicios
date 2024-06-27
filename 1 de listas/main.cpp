#include <iostream>
#include <conio.h>
using namespace std;
struct nodos
{
    int info;
    nodos *sgte;
};

char menu()
{
    cout<<"1: insertar en la lista"<<endl;
    cout<<"2: mostrar lista"<<endl;
    cout<<"3: buscar mayor"<<endl;
    cout<<"4: calcular promedio"<<endl;
    char opcion;
    do
    {
      opcion = getch();
    }while((opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4') && (opcion!=27));
    return opcion;
    }

nodos* buscarAnt(nodos* lista, nodos* aux)
{
    nodos *local=NULL;
    if(lista!=aux)
    {
        local=lista;
        while(local && local->sgte!=aux)
        {
            local=local->sgte;
        }
        return local;
    }
    else
        return NULL;
}
void agregarNext(nodos *&lista,int n)
{
    nodos* nuevo= new nodos();
    nuevo->info=n;
    if(n!=NULL)
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
nodos* getLast(nodos *lista)
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
void agregarLast(nodos *&lista,int n)
{
nodos* local= new nodos();
nodos* last=NULL;
local->info=n;
local->sgte=NULL;
if(lista!=NULL)
{
    last=getLast(lista);
    last->sgte=local;
}
else
{
    lista=local;
}
return;
}

void agregarFirst(nodos *&lista, int n)
{
    nodos *local = new nodos();
    nodos *aux = lista;
    local->info = n;
    lista=local;
    local->sgte = aux;
}

void agregar(nodos *&lista, int n)
{
 nodos *aux = lista;
 nodos *anterior = NULL;
 while(aux && aux->info<n)
 {
     aux = aux->sgte;
 }
 if (aux && aux!=lista)
 {
     anterior = buscarAnt(lista,aux);
     agregarNext(lista,n);
 }
  if (aux==NULL)
            agregarLast(lista,n);
       else if (aux==lista)
            agregarFirst(lista,n);
return;
    }


void mostrarL(nodos *lista)
{
    while(lista)
    {
        cout<<lista->info<<", ";
        lista=lista->sgte;
    }
    cout<<endl;
}

int main()
{
 char x;
 nodos *lista = NULL;
 nodos *listaux = NULL;
 int n;
 do
 {
     x=menu();
    switch(x)
    {
    case '1':
        cout<<"ingrese un numero"<<endl;
        cin>>n;
        agregar(lista,n);
         break;
    case '2':
        mostrarL(lista);

   break;
   case '3':
       listaux=lista;
       while(listaux && listaux->sgte)
       {
           listaux=listaux->sgte;
       }
       if(listaux)
       {
           cout<<"el mayor es: "<<listaux->info<<endl;
       }else
       {
           cout<<"la lista esta vacia"<<endl;
       }
break;
   case '4':
    listaux = lista;
    int cont=0;
    float total;
    if(!listaux)
    {
        cout<<"lista vacia"<<endl;
    }else{
    while(listaux)
    {
       total+=listaux->info;
       cont++;
       listaux=listaux->sgte;
    }
    cout<<"el promedio es: "<<total/cont<<endl;
    }
getch();
 }

}while(x!=27);
return 0;
}
