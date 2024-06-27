#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

struct nodoMes
{
 mesa info;
 nodoMes *sgte;
 nodoMes *ant;
};

struct nodoEsc
{
    esc info;
    nodoEsc *sgte;
    nodoMes *lmes;
};

struct mesa
{
  int nromes;
  int votos1;
  int votos2;
  int idEsc;
};

struct esc
{
  int id;
  char nom[100];
  int comuna;
  nodoMes *lmesa;
};

char mostrarmenu()
{
    cout<<"1: ingresar mesa"<<endl;
    cout<<"2: mostrar mesas"<<endl;
    cout<<"3: mostrar escuelas"<<endl;
    char opcion;
    do
    {
        opcion=getch();
    }while((opcion!='1')&&(opcion!='2')&&(opcion!='3')&&(opcion!=27));
    return opcion;
}

nodoMes* buscarAntM(nodoMes *aux)
{
    if(aux && aux->ant)
        {
           return aux=aux->ant;
        }
        else
            return NULL;
}

void insertNextM(nodoMes *&lista, mesa m)
{
    nodoMes *nuevo=new nodoMes();
    nuevo->info=m;
    if (lista!=NULL)
    {
        nuevo->sgte=lista->sgte;
        lista->sgte=nuevo;
        nuevo->ant=lista;
        if (nuevo->sgte)
        {
            nuevo->sgte->ant = nuevo;
        }
    }else
    {
        nuevo->sgte=lista;
        lista=nuevo;
        nuevo->ant=NULL;
    }
    return;
}

nodoEsc* buscarEsc(nodoEsc *raiz, int id)
{
    while (raiz && raiz->info.id!=id)
        raiz = raiz->sgte;
    return raiz;
}

void agregarMesa(nodoMes *listM, nodoEsc *listE)
{
    mesa m;
    cout<<"ingrese numero de mesa"<<endl;
    cin>>m.nromes;
    cout<<"ingrese cant de votos 1"<<endl;
    cin>>m.votos1;
    cout<<"ingrese cant de votos 2"<<endl;
    cin>>m.votos2;
    cout<<"ingrese id de escuela"<<endl;
    cin>>m.idEsc;
    nodoMes *aux=listM;
    nodoMes *ant=NULL;
    nodoEsc *auxE=listE;
    nodoEsc *auxE2=NULL;
    nodoEsc *nuevo=NULL;
    esc e;
    e.id=m.idEsc;
    while(aux && m.nromes>aux->info.nromes)
    {
        ant=aux;
        aux=aux->sgte;
    }
    if(aux)
    {
        ant=buscarAntM(aux);
        if(ant)
        {
          insertNextM(ant,m);
        }
        else
        {
            insertNextM(aux,m);
        }
        auxE2=buscarEsc(auxE,m.idEsc);
        if(auxE2)
        {
            insertNextM(auxE2->lmes,m);
        }

    }
    else
        {
            insertNextM(listM,m);
        }
    return;

}

int main()
{
    nodoMes *listaMesa=NULL;
    nodoEsc *listaEsc=NULL;
    char elegida;
    do
    {
        elegida=mostrarmenu();
        swtich(elegida)
        {
        case '1':
            agregarMesa(listaMesa,listaEsc);
        }
    }
    return 0;
}
