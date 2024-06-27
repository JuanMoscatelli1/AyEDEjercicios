#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct votos
{
    char localidad[20];
    int numeroLista;
    int cantVotos;
};

struct localidadConNumero
{
    char localidad[20];
    int numeroLoc;
};

int calcularPorcentaje(int votosLista,int totalVotos)
{
    return votosLista/totalVotos*100;
}

void mostrarTabla(int tabla[][5],int totalVotos)
{
    int mayor=999;
    int cantVotosPrimero;
    int cantVotosSegundo;
    int listaPrimera;
    for(int i=0;i<4;i++)
    {
        int porcentajeCero=calcularPorcentaje(tabla[i][0],totalVotos);
        cantVotosPrimero = tabla[i][0];
        listaPrimera=0;
        if(porcentajeCero >=50)
        {
            mayor=0;
        }
        cout<<"fila"<<i<<": "<<endl;
        for(int j=0;j<5;i++)
        {
            cout<<tabla[i][j]<<endl;
            int porcentajeCalculado=calcularPorcentaje(tabla[i][j],totalVotos);
            cout<<"Porcentaje: "<< porcentajeCalculado<<endl;
            if(porcentajeCalculado>porcentajeCero && porcentajeCalculado>50)
            {
                mayor = j;
            }
            if (tabla[i][j] > cantVotosPrimero)
            {
                cantVotosSegundo = cantVotosPrimero;
                cantVotosPrimero = tabla[i][j];
                listaPrimera=j;
            }

        }
        if(mayor != 999)
           {
             cout<<"La lista Ganadora es la lista: " <<j<<endl;
           }else
           {
               if(cantVotosPrimero-cantVotosSegundo>(totalVotos/10))
               {
                   cout<<"La lista Ganadora es la lista: "<<listaPrimera<<endl;
               }else
               {
                   cout<<"Las dos listas que deben pasar son: "<<
               }
           }
    }
    return;
}

void agregarVotos(int tabla[][5],localidadConNumero vecLoc[])
{
    FILE*f;
    f=fopen("elecciones.dat","rb");
    votos vot;
    int totalVotos;
    while(fread(&vot,sizeof(vot),1,f))
    {
        if(vot.localidad==vecLoc[0].localidad)
        {
            tabla[0][vot.numeroLista]+= vot.cantVotos;
            totalVotos+=vot.cantVotos;
        }
        if(vot.localidad==vecLoc[1].localidad)
        {
            tabla[1][vot.numeroLista]+= vot.cantVotos;
            totalVotos+=vot.cantVotos;
        }
        if(vot.localidad==vecLoc[2].localidad)
        {
            tabla[2][vot.numeroLista]+= vot.cantVotos;
            totalVotos+=vot.cantVotos;
        }
        if(vot.localidad==vecLoc[3].localidad)
        {
            tabla[3][vot.numeroLista]+= vot.cantVotos;
            totalVotos+=vot.cantVotos;
        }
    }

    mostrarTabla(tabla,totalVotos);

}

void inicializarTabla(int tabla)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;i++)
        {
            tabla[i][j]=0;
        }
    }
    return;
}

int main()
{

    int tabla[4][5];
    inicializarTabla(tabla);
    localidadConNumero vecLoc[4];
    agregarVotos(tabla,vecLoc);
    vecLoc[0].localidad="Pinamar";
    vecLoc[0].numeroLoc=1;
    vecLoc[1].localidad="Carilo";
    vecLoc[1].numeroLoc=2;
    vecLoc[2].localidad="Ostende";
    vecLoc[2].numeroLoc=3;
    vecLoc[3].localidad="ValeriaDelmar";
    vecLoc[3].numeroLoc=4;
    return 0;
}

/* d) a) Si, el vector de las localidades, ya que adentro del archivo ya estaria el numero de la localidad
d) b) propondria una lista simplemente enlazada para cada localidad ya que asi se podrian agregar o sacar nodos que tengan a los partidos
