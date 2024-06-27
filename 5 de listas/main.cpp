#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

struct alumno
{
    char nombre[50];
    char apellido[50];
    char dni[11];
    int legajo;
    int codcarrera;
};

struct nodoAl
{
 alumno info;
 nodoAl *sgte;
};

void cargarArchivo()
{
  FILE *f;
  f = fopen("alumni.data","w");
  alumno a;
  if(f)
  {
     strcpy(a.apellido,"Uno");
     strcpy(a.nombre,"Uno");
     strcpy(a.dni,"123123");
     a.codcarrera=1;
     a.legajo=111;
     fwrite(&a,sizeof(alumno),1,f);

     strcpy(a.apellido,"Dos");
     strcpy(a.nombre,"Dos");
     strcpy(a.dni,"2222");
     a.codcarrera=1;
     a.legajo=222;
     fwrite(&a,sizeof(alumno),1,f);

     strcpy(a.apellido,"Tres");
     strcpy(a.nombre,"Tres");
     strcpy(a.dni,"3333");
     a.codcarrera=1;
     a.legajo=333;
     fwrite(&a,sizeof(alumno),1,f);
     fclose(f);
     cout<<"se ha cargado el archivo"<<endl;
  }else
  {
      cout<<"no se ha podido cargar"<<endl;
  }
    return;
}

void insertarAlumno(nodoAl *&lista, alumno a)
{
 nodoAl *nuevo = new nodoAl();
 nuevo->info=a;
 if(lista!=NULL)
 {
     nuevo->sgte=lista->sgte;
     lista->sgte=nuevo;
 }
 else
    {
        nuevo->sgte=lista;
        lista=nuevo;

    }
    return;
}

void mostrarLista(nodoAl *lista)
{
    while(lista)
    {
        cout << "Apellido y nombre: " << lista->info.apellido << ", " << lista->info.nombre << endl;
        cout << "DNI: " << lista->info.dni << endl;
        cout << "Legajo: " << lista->info.legajo << endl;
        cout << "Carrera: " << lista->info.codcarrera<< endl << endl;
        lista =lista->sgte;
    }
    return;
}

void borrarLista(nodoAl *&lista)
{
  nodoAl *paux;
  nodoAl *last;
  while(lista!=NULL)
  {
      paux=lista;
      last=NULL;
      while(paux && paux->sgte)
      {
          last=paux;
          paux=paux->sgte;
      }
      if(paux)
      {
          delete paux;
          if(last!=NULL)
          {
              last->sgte = NULL;
          }else
          {
            lista = NULL;
          }
      }
  }
  return;
}

int main()
{
    FILE *f;
    nodoAl *lista = NULL;
    alumno a;
    cargarArchivo();
    if(f=fopen("alumni.data","r"))
    {
    fread(&a,sizeof(alumno),1,f);
    while(!feof(f))
    {
        insertarAlumno(lista,a);
        fread(&a,sizeof(alumno),1,f);
    }
    fclose(f);
    }
    mostrarLista(lista);
    borrarLista(lista);


    return 0;
}
