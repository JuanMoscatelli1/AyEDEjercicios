#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>

#define ruta1 "archivouno.data"
#define ruta2 "archivodos.data"
#define ruta3 "archivofusion.data"
#define ruta4 "archivoordenado.data"

using namespace std;

void mostrarArchivo(char ruta[])
{
    cout<<"Numeros: "<<endl;
    FILE *f;
    int aMostrar;
    if(f=fopen(ruta,"rb"))
    {
        fread(&aMostrar,sizeof(int),1,f);
        while(!feof(f))
        {
            cout<<aMostrar<<"|";
            fread(&aMostrar,sizeof(int),1,f);
        }
        fclose(f);
    }
    cout<<endl;
    return;
}

void agregarDatos(FILE* f,int v[],char ruta[],int tam)
{
    if(f=fopen(ruta,"ab"))
       {
           fwrite(v,sizeof(int),tam,f);
       }
       fclose(f);
       return;
}

void fusionarIntercalado(char rutauno[],char rutados[],char rutatres[])
{
    FILE *f1;
    FILE *f2;
    FILE *f3;
    int x1,x2;
    f1=fopen(rutauno,"rb");
    f2=fopen(rutados,"rb");
    f3=fopen(rutatres,"wb");
    while(fread(&x1,sizeof(int),1,f1) && fread(&x2,sizeof(int),1,f2))
    {
        fwrite(&x1,sizeof(int),1,f3);
        fwrite(&x2,sizeof(int),1,f3);
    }
    while(!feof(f1))
    {
         fwrite(&x1,sizeof(int),1,f3);
         fread(&x1,sizeof(int),1,f1);
    }
    while(!feof(f2))
    {
         fwrite(&x2,sizeof(int),1,f3);
         fread(&x2,sizeof(int),1,f2);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return;
}

void fusionarOrdenado(char rutauno[],char rutados[], char rutacuatro[])
{
    FILE *f1;
    FILE *f2;
    FILE *f3;
    f1=fopen(rutauno,"rb");
    f2=fopen(rutados,"rb");
    f3=fopen(rutacuatro,"wb");
    int x1,x2;
     while(fread(&x1,sizeof(int),1,f1) && fread(&x2,sizeof(int),1,f2))
    {
        if(x1<x2)
        {
            fwrite(&x1,sizeof(int),1,f3);
            fseek(f2,(-1)*sizeof(int),SEEK_CUR);
        }else
        {
            fwrite(&x2,sizeof(int),1,f3);
            fseek(f1,(-1)*sizeof(int),SEEK_CUR);
        }
    }
    while(!feof(f1))
    {
         fwrite(&x1,sizeof(int),1,f3);
         fread(&x1,sizeof(int),1,f1);
    }
    while(!feof(f2))
    {
         fwrite(&x2,sizeof(int),1,f3);
         fread(&x2,sizeof(int),1,f2);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);

    return;
}

int main()
{
    FILE* f1;
    FILE* f2;
    int v1[]={1,5,7,14};
    int v2[]={3,22};
    agregarDatos(f1,v1,ruta1,4);
    agregarDatos(f2,v2,ruta2,2);
    mostrarArchivo(ruta1);
    mostrarArchivo(ruta2);
    cout<<endl;
    cout<<"*************************"<<endl;
    fusionarIntercalado(ruta1,ruta2,ruta3);
    mostrarArchivo(ruta3);
    cout<<endl;
    cout<<"Archivo fusion ordenado: "<<endl;
    fusionarOrdenado(ruta1,ruta2,ruta4);
    mostrarArchivo(ruta4);
    return 0;
}
