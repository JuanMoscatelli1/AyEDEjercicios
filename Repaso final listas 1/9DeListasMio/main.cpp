#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

struct mesa
{
    int nroMesa;
    int cantVotos1;
    int cantVotos2;
    int idEsc;
};

struct escuela
{
   int idEscuela;
   char nombreEsc[100];
   int nroComuna;
};

struct nodoListaMesa
{
    mesa info;
    nodoListaMesa *sgte;
    nodoListaMesa *ant;
};

struct nodoListaEscuela
{
    escuela info;
    nodoListaEscuela *sgte;
    nodoListaMesa *listaMesas;
};

char mostrarMenu(void)
{
    cout<<"Ingrese una opcion"<<endl;
    cout<<"Presione 1 para ingresar una mesa"<<endl;
    cout<<"Presione 2 para mostrar la lista de escuelas"<<endl;
    cout<<"Presione 3 para borrar la lista(test)"<<endl;
    char opcion;
    do
    {
        opcion=getch();
    }while((opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!=27));
    return opcion;
}

nodoListaEscuela *buscarNodoEscuela(nodoListaEscuela *lista,int id)
{
    while(lista && lista->info.idEscuela != id)
    {
        lista = lista->sgte;
    }
    return lista;
}

void insertarMesaSiguiente(nodoListaMesa *&lista,mesa Mesa)
{
    nodoListaMesa *nuevo = new nodoListaMesa();
    nuevo->info=Mesa;
    if(lista!=NULL)
    {
        nuevo->sgte=lista->sgte;
        lista->sgte=nuevo;
        nuevo->ant=lista;
        if(nuevo->sgte)
        {
            nuevo->sgte->ant=nuevo;
        }
    }else
    {
        nuevo->sgte=lista;
        lista=nuevo;
        nuevo->ant=NULL;
    }


    return;
}

nodoListaMesa *obtenerUltimoMesa(nodoListaMesa *lista)
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

void insertarMesaAlFinal(nodoListaMesa *&lista,mesa Mesa)
{
    nodoListaMesa *aux = NULL;
    aux = obtenerUltimoMesa(aux);
    if(aux)
    {
        insertarMesaSiguiente(aux,Mesa);
    }else
    {
        insertarMesaSiguiente(lista,Mesa);
    }
    return;
}

void insertarMesaAlPrincipio(nodoListaMesa *&lista,mesa Mesa)
{
    nodoListaMesa *nuevo = new nodoListaMesa();
    nodoListaMesa *aux = lista;
    nuevo->info = Mesa;
    lista=nuevo;
    nuevo->sgte = aux;
    aux->ant=nuevo;
    nuevo->ant=NULL;
    return;
}


void insertarMesaDEOrdenado(nodoListaMesa *&lista,mesa Mesa)
{
    nodoListaMesa *aux =lista;
    nodoListaMesa *anterior = NULL;
    while(aux && aux->info.nroMesa<Mesa.nroMesa)
    {
        aux = aux->sgte;
    }
    if(aux && aux !=lista)
    {
        anterior=aux->ant;
        insertarMesaSiguiente(anterior,Mesa);
    }
    else
        {
            if(aux==NULL)
            {
                insertarMesaAlFinal(lista,Mesa);
            }else
            {
                if(aux == lista)
                {
                    insertarMesaAlPrincipio(lista,Mesa);
                }
            }
        }
        return;
}

nodoListaEscuela *buscarUltimaEscuela(nodoListaEscuela *lista)
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

void insertarEscuelaSiguiente(nodoListaEscuela *&lista,escuela Esc)
{
  nodoListaEscuela *nuevo = new nodoListaEscuela();
  nuevo->info=Esc;
  if(lista)
  {
      nuevo->sgte=lista->sgte;
      lista->sgte=nuevo;
  }else
  {
      nuevo->sgte=lista;
      lista=nuevo;
  }
    return;
}

void insertarEscuelaAlFinal(nodoListaEscuela *&lista,escuela Esc)
{

    nodoListaEscuela *aux=buscarUltimaEscuela(lista);
    if(aux)
    {
       insertarEscuelaSiguiente(aux,Esc);

    }else
    {
        insertarEscuelaSiguiente(lista,Esc);
    }
    return;
}

void agregarMesa(nodoListaEscuela *&listaEscuela,mesa Mesa)
{
    escuela escNueva;
   nodoListaEscuela *aux = buscarNodoEscuela(listaEscuela,Mesa.idEsc);
   if(aux)
   {
       insertarMesaDEOrdenado(aux->listaMesas,Mesa);
   }else
   {
       cout<<"La escuela no existe, ingrese sus datos: "<<endl;
       cout<<"Ingrese el nombre sin espacios pls"<<endl;
       cin>>escNueva.nombreEsc;
       escNueva.idEscuela = Mesa.idEsc;
       cout<<"Ingrese el numero de comuna"<<endl;
       cin>>escNueva.nroComuna;
       insertarEscuelaAlFinal(listaEscuela,escNueva);
       aux=buscarNodoEscuela(listaEscuela,Mesa.idEsc);
       if(aux)
       {
           insertarMesaDEOrdenado(aux->listaMesas,Mesa);
       }
   }
   return;
}

void mostrarEsc(nodoListaEscuela *lista)
{
    nodoListaMesa *aux =NULL;
    if(lista)
    {
      while(lista)
    {
        cout<<"ID: "<<lista->info.idEscuela<<endl;
        cout<<"Nombre: "<<lista->info.nombreEsc<<endl;
        cout<<"Numero de comuna: "<<lista->info.nroComuna<<endl;
        aux=lista->listaMesas;
        cout<<endl;
        cout<<"Las mesas que tiene:"<<endl;
        while(aux)
        {
           cout<<"Numero de mesa: "<<aux->info.nroMesa<<endl;
           cout<<"Cantidad votos 1: "<<aux->info.cantVotos1<<endl;
           cout<<"Cantidad votos 2: "<<aux->info.cantVotos2<<endl;
           aux=aux->sgte;
        }
      lista=lista->sgte;
        }
    }else
    {
        cout<<"La lista esta vacia"<<endl;
    }

    return;

}

void borrarListaMesas(nodoListaMesa *&lista)
{
    nodoListaMesa *aux;
    nodoListaMesa *anterior;
    while(lista!=NULL)
    {
        anterior=NULL;
        aux=lista;
        while(aux && aux->sgte)
        {
            anterior=aux;
            aux = aux->sgte;
        }if(aux)
        {
            delete aux;
            if(anterior!=NULL)
            {
                anterior->sgte=NULL;
            }else
                lista=NULL;
        }
    }
    return;
}

void borrarListaEscuela(nodoListaEscuela *&lista)
{
    nodoListaEscuela *aux;
    nodoListaEscuela *anterior;
    while(lista!=NULL)
    {
        anterior=NULL;
        aux=lista;
        while(aux && aux->sgte)
        {
            anterior=aux;
            aux = aux->sgte;
        }if(aux)
        {
            borrarListaMesas(aux->listaMesas);
            delete aux;
            if(anterior!=NULL)
            {
                anterior->sgte=NULL;
            }else
                lista=NULL;
        }
    }
    return;
}

int main()
{
    char opcion;
    mesa mesaAInsertar;
    nodoListaEscuela *lesc=NULL;
    do
    {
        opcion = mostrarMenu();
        switch(opcion)
        {
        case '1':
            cout<<"Ingrese el numero de mesa"<<endl;
            cin>>mesaAInsertar.nroMesa;
            cout<<"Ingrese el id de la escuela"<<endl;
            cin>>mesaAInsertar.idEsc;
            cout<<"Ingrese la cantidad de votos 1"<<endl;
            cin>>mesaAInsertar.cantVotos1;
            cout<<"Ingrese la cantidad de votos 2"<<endl;
            cin>>mesaAInsertar.cantVotos2;
            agregarMesa(lesc,mesaAInsertar);
            if(lesc)
            {
                cout<<"funca"<<endl;
            }else
            {
                cout<<"no funca"<<endl;
            }
            break;
        case '2':
            mostrarEsc(lesc);
            break;
        case '3':
            borrarListaEscuela(lesc);
            break;

        }
    }while(opcion!=27);

    borrarListaEscuela(lesc);
    return 0;
}
