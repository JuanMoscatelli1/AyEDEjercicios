#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

struct escuela
{
    int id;
    char nombre[100];
    int nroComuna;
};

struct mesa
{
    int nroMesa;
    int votos1;
    int votos2;
    int idEsc;
};

struct nodoMes
{
    mesa info;
    nodoMes *sgte;
    nodoMes *ant;
};

struct nodoEsc
{
    escuela info;
    nodoEsc *sgte;
    nodoMes *listaMes;
};

nodoEsc *ObtenerUltimo(nodoEsc * p)
{
    if (p)
    {
        while (p->sgte)
        {
            p = p->sgte;
        }
    }
    return p;

}


char mostrarMenu()
{
    cout<<"1: agregar mesa"<<endl;
    cout<<"2: mostrar mesas"<<endl;
    cout<<"3: mostrar escuelas"<<endl;
    char opcion;
    do
    {
        opcion = getch();
    }while((opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!=27));
    return opcion;
}

nodoMes* buscarAntMes(nodoMes *nodo)
{
    if (nodo && nodo->ant)
    {
        return nodo->ant;
    }
    else
        return NULL;
}

void insertarNextMes (nodoMes  *&n, mesa x)
{
    nodoMes *nuevo= new nodoMes();
    nuevo->info=x;
    if (n!=NULL)
    {
        nuevo->sgte= n->sgte;
        n->sgte = nuevo;
        nuevo->ant=n;
        if (nuevo->sgte)
        {
            nuevo->sgte->ant = nuevo;
        }
    }
    else
    {
        nuevo->sgte= n;
        n= nuevo;
        nuevo->ant=NULL;
    }

    return;
}
void mostrarMesas(nodoMes *aux)
{
    nodoMes *lmesa=aux;
    while(lmesa)
    {
        cout<<"numero de mesa: "<<lmesa->info.nroMesa<<endl;
        cout<<"numero votos 1: "<<lmesa->info.votos1<<endl;
        cout<<"numero votos 2: "<<lmesa->info.votos2<<endl;
        cout<<"id de escuela de la mesa: "<<lmesa->info.idEsc<<endl;
        lmesa=lmesa->sgte;
    }
    return;
}

void mostrarEsc(nodoEsc *lescorig,nodoEsc *lesc,nodoMes *aux)
{
    lesc=lescorig;
        while(lesc)
        {
        aux=lesc->listaMes;
        cout<<"*************"<<endl;
        cout<<"id esc: "<<lesc->info.id<<endl;
        cout<<"nombre: "<<lesc->info.nombre<<endl;
        cout<<"nro comuna: "<<lesc->info.nroComuna<<endl;
        cout<<"ooooooooooooo"<<endl;
        cout<<"mesas de la escuela: "<<endl;

        while(aux)
        {
            cout<<"nro de mesa: "<<aux->info.nroMesa<<endl;
            cout<<"numero votos 1: "<<aux->info.votos1<<endl;
            cout<<"numero votos 2: "<<aux->info.votos2<<endl;
            cout<<"id de escuela de la mesa: "<<aux->info.idEsc<<endl;
            aux=aux->sgte;
        }
        lesc=lesc->sgte;
        }
        return;
}

nodoEsc* buscarEsc(nodoEsc * raiz, int id)
{
    while (raiz && raiz->info.id!=id)
        raiz = raiz->sgte;
    return raiz;
}

void insertarNextEsc(nodoEsc *&n,escuela x)
{
    nodoEsc *nuevo= new nodoEsc();
    nuevo->info=x;
    if (n!=NULL)
    {
        nuevo->sgte= n->sgte;
        n->sgte = nuevo;
    }
    else
    {
        nuevo->sgte= n;
        n= nuevo;
    }

    return;
}


void procesarMesa(nodoMes *&lmesa,nodoEsc *&lesc)
{

    mesa m;
    cout<<"ingrese numero de mesa"<<endl;
    cin>>m.nroMesa;
    cout<<"ingrese la cantidad de votos del partido 1"<<endl;
    cin>>m.votos1;
    cout<<"ingrese la cantidad de votos del partido 2"<<endl;
    cin>>m.votos2;
    cout<<"ingrese el id de la escuela"<<endl;
    cin>>m.idEsc;
    nodoMes *aux = lmesa;
    nodoMes *anterior=NULL;
    nodoEsc *auxEsc2=lesc;
    nodoEsc *auxEsc =NULL;
    escuela es;
    es.id=m.idEsc;

    while(aux && m.nroMesa>aux->info.nroMesa)
    {

      aux=aux->sgte;
    }
    if(aux)
    {
       anterior=buscarAntMes(aux);
    insertarNextMes(anterior,m);
    }else
    {
      insertarNextMes(lmesa,m);
    }

        auxEsc=buscarEsc(auxEsc2,m.idEsc);
        if(auxEsc)
        {

            insertarNextMes(auxEsc->listaMes,m);
        }else
    {
        cout<<"la escuela no esta en la lista, indique los datos: "<<endl;
        cout<<"ingrese el nombre (sin espacios): "<<endl;
        cin>>es.nombre;
        cout<<"ingrese el numero de comuna: "<<endl;
        cin>>es.nroComuna;
        insertarNextEsc(lesc,es);
        auxEsc= buscarEsc(lesc, m.idEsc);
        if (auxEsc)
            insertarNextMes(auxEsc->listaMes,m);

    }

    return;
}

void borrarListaMes(nodoMes *&lista)
{
    nodoMes *anterior;
    nodoMes *paux;
    while (lista!=NULL)
    {
        anterior=NULL;
        paux= lista;
        while (paux && paux->sgte)
        {
            anterior = paux;
            paux= paux->sgte;
        }
        if (paux)
        {
            delete paux;
            if (anterior!=NULL)
                anterior->sgte=NULL;
            else
                lista =NULL;
        }
    }
    return;
}


void borrarListaEsc(nodoEsc *&lista)
{
    nodoEsc *anterior;
    nodoEsc *paux;
    while (lista!=NULL)
    {
        anterior=NULL;
        paux= lista;
        while (paux && paux->sgte)
        {
            anterior = paux;
            paux= paux->sgte;
        }
        if (paux)
        {
            borrarListaMes(paux->listaMes);
            delete paux;
            if (anterior!=NULL)
                anterior->sgte=NULL;
            else
                lista =NULL;
        }
    }
    return;
}


int main()
{

    nodoMes *lmesa=NULL;
    nodoMes *lmesa2=NULL;
    nodoEsc *lesc=NULL;
    nodoEsc *mostr=NULL;
    nodoEsc *mostraux=NULL;
    nodoMes *mesAux=NULL;

    char elegida;
    do
    {
        elegida=mostrarMenu();
        switch(elegida)
        {
        case '1':
            procesarMesa(lmesa,lesc);
            break;
        case '2':
            lmesa2 = lmesa;
            mostrarMesas(lmesa2);
            break;
        case '3':
            mostr=lesc;
            mostrarEsc(mostr,mostraux,mesAux);
            break;

        }

    } while(elegida!=27);
borrarListaEsc(lesc);
return 0;
}
