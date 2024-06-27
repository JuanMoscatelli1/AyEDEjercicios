#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
#include "listaAlumnos.h"

#define RUTA_ALUMNOS "archivoalumnos.data"
#define RUTA_MATERIAS "archivomaterias.data"
using namespace std;

struct alumno
{
    char nombre[50];
    char apellido[50];
    char dni[11];
    int legajo;
    int codcarrera;
    nodoMa *listaMa;
};

struct materia
{
   char nombreMateria[50];
   char fechaAprobacion[11];
    int legajo;
    int nota;
    int libro;
    int folio;
};

struct nodoAl
{
   alumno info;
   nodoAl *sgte;

};

struct nodoMa
{
    materia info;
    nodoMa *sgte;
};



int main()
{
    nodoAl *listaAl =NULL;




    return 0;
}
