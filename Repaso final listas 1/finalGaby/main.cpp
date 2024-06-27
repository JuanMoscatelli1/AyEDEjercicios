#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;

struct tipoUno
{
    int campo1;
    cad20 campo2;
    float campo3;
    int campo4;
};

struct tipoDos
{
    float campo3;
    int campo4;
};

struct tipoDosSub
{
    tipoDos info;
    tipoDosSub *sgte;
};

struct tipoUnoSub
{
    int campo1;
    cad20 campo2;
    tipoDosSub *sublista;

};

struct listaNueva
{
    tipoUnoSub info;
    listaNueva *sgte;
};

struct listaDato
{
    tipoUno info;
    listaDato *sgte;
};

listaNueva *cargarLista(listaDato *listadato)
{
    listaNueva *nueva=NULL;
    tipoUno dato;
    tipoUnoSub datoSub;
    tipoDos dato2Sub;
    while(listadato->sgte)
    {
        dato= Pop(listadato);
        datoSub.campo1=dato.campo1;
        datoSub.campo2=dato.campo2;
        dato2Sub.campo3=dato.campo3;
        dato2Sub.campo4=dato.campo4;
        insertarOrdenado(datoSub.sublista,dato2Sub);
        while(listadato->sgte && (listadato->info.campo1==listadato->sgte->info.campo1) && (listadato->info.campo2==listadato->sgte->info.campo2))
        {
            listadato=listadato->sgte;
            dato=Pop(listadato);
            dato2Sub.campo3=dato.campo3;
            dato2Sub.campo4=dato.campo4;
            insertarOrdenado(datoSub.sublista,dato2Sub);

        }
        insertarSinRepetir(nueva,datoSub);


    }
    return nueva;
}

int main()
{
    listaDato *listadato=NULL;
    listaNueva *resultado=cargarLista(listadato);
    return 0;
}

/* Si en una empresa de electrodomesticos quiero acceder a las ventas de un dia, las cuales estan en una lista:
    Si estan en la lista con sublistas, es mas facil porque habra un solo nodo con todas las ventas en la sublista, mientras que
        en la lista repetida hay que recorrerla entera.
   Si quiero ordenar la lista: de las dos formas se puede, aunque en la que tiene sublistas solo por los campos1 y 2, aunque luego se podrá
        ordenar su sublista.
   Si quiero eliminar un nodo: si es por los campos 1 o 2 es mas rapido en la que tiene sublistas ya que tiene menos elementos,
        pero si es por campos 3 o 4 en la de sublistas, habra que encontrar primero el nodo principal y luego recorrer la sublista para encontrar
        el nodo a borrar
   Si quiero mostrar u obtener la lista entera, hay que recorrer la lista repetida 1 sola vez pero para la que tiene sublistas hay que recorrer todas
        las sublistas
