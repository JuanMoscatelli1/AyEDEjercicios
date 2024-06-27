#include <iostream>
#include <string.h>
using namespace std;

struct NodoListaSE
{
    int info;             // Datos de el nodo
    NodoListaSE   *sgte;  // Puntero al siguiente nodo

};



NodoListaSE *ObtenerUltimo(NodoListaSE * p)
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


void InsertarSiguiente (NodoListaSE  *&n, char x)
{
    NodoListaSE *nuevo= new NodoListaSE();
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


void InsertarAlFinal(NodoListaSE *&lista, char x)
{
    NodoListaSE *aux;
    aux=ObtenerUltimo(lista);
    if (aux)
    {
        InsertarSiguiente(aux,x);
    }
    else
    {
        InsertarSiguiente(lista,x);
    }
    return;
}


void cqueue(NodoListaSE *&cola, char x)
{
    InsertarAlFinal(cola,x);
}

char dequeue(NodoListaSE *&cola)
{
    NodoListaSE *aux;
    char x;
    if (cola)
    {
        aux= cola;
        x= aux->info;
        cola= aux->sgte;
        delete aux;
        return x;
    }
    return NULL;
}

void mostrar(NodoListaSE *lista)
{
    NodoListaSE *auxlista = lista;
    while(auxlista)
    {
        cout << auxlista->info << endl;
        auxlista = auxlista->sgte;
    }
}
void ingresar(char vec[])
{
    cout<<"ingrese el numero"<<endl;
    cin>>vec;
    return;
}

NodoListaSE* BuscarNodoAnterior(NodoListaSE * raiz, NodoListaSE * anterior_a)
{
    NodoListaSE *p =NULL;
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
void BorrarSiguiente(NodoListaSE  *n)
{
    NodoListaSE  *aborrar = n->sgte;
    NodoListaSE  *sgteaborrar;
    if (aborrar)
        sgteaborrar= aborrar->sgte;
    else
        sgteaborrar = NULL;
    n->sgte = sgteaborrar;
    delete aborrar;
    return;
}

void borrarNodo(NodoListaSE *& raiz, NodoListaSE * aborrar)
{
    if (raiz && aborrar)
    {
        if (aborrar==raiz)
        {
            raiz = raiz->sgte;
            delete aborrar;
        }
        else
        {
            NodoListaSE *x = BuscarNodoAnterior(raiz,aborrar);
            BorrarSiguiente(x);
        }
    }
    return;
}


void push(NodoListaSE *&pila, char info)
{
    InsertarAlFinal(pila,info);
}


char pop(NodoListaSE *&pila)
{
    NodoListaSE *ultimo;
    ultimo= ObtenerUltimo(pila);
    if (ultimo)
    {
        char aux = ultimo->info;
        borrarNodo(pila,ultimo);
        return aux;
    }
    return NULL;
}
int main()
{
    NodoListaSE *cola =NULL;
    NodoListaSE *pila= NULL;
    int tam;
    char *vec = new char[tam];
    ingresar(vec);
    tam=strlen(vec);
    cout<<tam<<endl;
    cout<<vec<<endl;
    for(int i=0;i<tam;i++)
    {
     cqueue(cola,vec[i]);
     push(pila,vec[i]);
    }
    cout<<"cola:"<<endl;
    while(cola)
    {
        cout<<cola->info;
        cola=cola->sgte;

    }
    cout<<endl;
    cout<<"pila:"<<endl;
    while(pila)
    {
        cout<<pila->info;
        pila=pila->sgte;
    }
    cout<<endl;

    char ca= dequeue(cola);
    char pa=pop(pila);

    cout<<ca;
    cout<<pa;


    int cont = 0;
    for(int j=0;j<tam/2;j++)
    {
        char c =dequeue(cola);

        char p =pop(pila);

        if(c==p)
        {
         cont++;
        }
    }
    cout<<cont<<endl;
    cout<<tam<<endl;
if(cont==tam/2)
{
    cout<<"es capicua"<<endl;
}else
{
    cout<<"no es capicua"<<endl;
}
return 0;
}
