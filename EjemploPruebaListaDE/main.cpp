#include <iostream>
#include <conio.h>
#include "listasDE.h"

using namespace std;

int main()
{
    NodoListaDE *miLista=NULL;
    NodoListaDE *aux;
    ListaDEInsertarAlFinal(miLista, 8);
    ListaDEInsertarAlFinal(miLista, 10);
    ListaDEInsertarAlFinal(miLista, 16);
    ListaDEInsertarAlFinal(miLista, 5);
    ListaDEInsertarAlFinal(miLista, 7);
    ListaDEInsertarAlFinal(miLista, 19);
    ListaDEInsertarAlFinal(miLista, 1);
    ListaDEInsertarAlFinal(miLista, 2);
    aux= ListaDEBuscarNodo(miLista,7);
    if (aux) //si lo encontró inserta
        ListaDEInsertarSiguiente(aux,12);
    else
        cout << "Error: no encontró nodo con 7." << endl;
    ListaDEInsertarPrimero(miLista,1000);
    cout << "Intentemos borrar el nodo que contiene 19:" << endl;
    aux= ListaDEBuscarNodo(miLista,19);
    ListaDEborrarNodo(miLista,aux);
    cout << "Recorremos la lista de principio a fin utilizando puntero al siguiente:" << endl;
    aux = miLista;
    while (aux)
    {
        cout << "Info: " << aux->info << endl;
        aux= aux->sgte;
    }
    getch();
    cout << "Recorremos toda la lista en sentido inverso utilizando puntero al anterior:" << endl;
    aux = ListaDEObtenerUltimo(miLista);
    while (aux)
    {
        cout << "Info: " << aux->info << endl;
        aux= aux->ant;
    }
    getch();
    return 0;
}
