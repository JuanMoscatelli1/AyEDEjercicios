#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#define NOMBREARCHIVO "miarchivo.ayed"
#define NOMBREARCHIVOAUX "archivoReescrito.ayed"

using namespace std;

struct alumno
{
    char nombre[15];
    char dni[10];
    int edad;
    bool borrado=false;
    int legajo;
};

void guardarAlumno()
{
    alumno al;
    cout<<"Ingrese el nombre"<<endl;
    cin>>al.nombre;
    cout<<"Ingrese el dni"<<endl;
    cin>>al.dni;
    cout<<"Ingrese la edad"<<endl;
    cin>>al.edad;
    cout<<"Ingrese el legajo"<<endl;
    cin>>al.legajo;
    FILE*f;
    if(f=fopen(NOMBREARCHIVO,"ab"))
    {
        fwrite(&al,sizeof(alumno),1,f);
        fclose(f);
        cout<<"Se ha agregado el alumno"<<endl;
    }else
    {
        cout<<"No se ha podido agregar"<<endl;
    }
    return;
}

void mostrarTodo(char ruta1[])
{
    FILE* f;
    alumno al;
    if(f=fopen(ruta1,"rb"))
    {
        while(fread(&al,sizeof(alumno),1,f))
        {
        cout<<"Datos del alumno:"<<endl;
        cout<<"Nombre: "<<al.nombre<<endl;
        cout<<"DNI: "<<al.dni<<endl;
        cout<<"Edad: "<<al.edad<<endl;
        cout<<"Legajo: "<<al.legajo<<endl;
        cout<<endl;
        }
    }
    fclose(f);
    return;
}

void mostrarNoBorrados()
{
    FILE* f;
    alumno al;
    if(f=fopen(NOMBREARCHIVO,"rb"))
    {
        while(fread(&al,sizeof(alumno),1,f))
        {
        if(!al.borrado)
        {
            cout<<"Datos del alumno:"<<endl;
            cout<<"Nombre: "<<al.nombre<<endl;
            cout<<"DNI: "<<al.dni<<endl;
            cout<<"Edad: "<<al.edad<<endl;
            cout<<"Legajo: "<<al.legajo<<endl;
            cout<<endl;
        }
      }
    }
    fclose(f);
    return;

}

void buscarPorDni()
{
    char dniABuscar[10];
    FILE*f;
    alumno al;
    int encontrado = 0;
    cout<<"Ingrese dni"<<endl;
    cin>>dniABuscar;
    if(f=fopen(NOMBREARCHIVO,"rb"))
    {
        while(fread(&al,sizeof(alumno),1,f) && (!encontrado))
        {
            if(strcmp(dniABuscar,al.dni)==0)
            {
                encontrado = 1;
                cout<<"Datos del alumno:"<<endl;
                cout<<"Nombre: "<<al.nombre<<endl;
                cout<<"DNI: "<<al.dni<<endl;
                cout<<"Edad: "<<al.edad<<endl;
                cout<<"Legajo: "<<al.legajo<<endl;
            }
        }
    }
    if(!encontrado)
    {
        cout<<"No se ha encontrado al alumno"<<endl;
    }
    fclose(f);
    return;
}

void borradoLogico()
{
    char dniABuscar[10];
    FILE*f;
    alumno al;
    int encontrado = 0;
    cout<<"Ingrese dni"<<endl;
    cin>>dniABuscar;
    if(f=fopen(NOMBREARCHIVO,"rb+"))
    {
        while(!encontrado && fread(&al,sizeof(alumno),1,f))
        {
            if(strcmp(dniABuscar,al.dni)==0)
            {
                encontrado = 1;
                al.borrado=true;
                fseek(f,(-1)*sizeof(alumno),SEEK_CUR);
                fwrite(&al,sizeof(alumno),1,f);
            }
        }
    }
    if(!encontrado)
    {
        cout<<"No se ha encontrado al alumno"<<endl;
    }else
    {
        cout<<"Se ha marcado al alumno como borrado"<<endl;
    }
    fclose(f);
    return;
}

void borrarArchivo(void)
{
    FILE *f;
    FILE *aux;
    alumno al;
    aux = fopen(NOMBREARCHIVOAUX,"wb");
    if(f=fopen(NOMBREARCHIVO,"rb+"));
    {
        while(fread(&al,sizeof(alumno),1,f))
        {
            if(!al.borrado)
            {
                fwrite(&al,sizeof(alumno),1,aux);
            }
        }
        fclose(f);
    }
    fclose(aux);
    if(!remove(NOMBREARCHIVO))
    {
        if(!rename(NOMBREARCHIVOAUX,NOMBREARCHIVO))
        {
            cout<<"Se ha renombrado el archivo";
        }
    }else
    {
        cout<<"No se ha podido borrar"<<endl;
    }
    return;
}

void ordenarArchivo(char ruta[])
{
    FILE* f;
    alumno al;
    alumno aux;
    alumno v[15];
    int cont=0;

    if(f=fopen(ruta,"rb+"))
    {
       while(fread(&al,sizeof(alumno),1,f))
       {
           v[cont]=al;
           cont++;
       }

       for(int i=0;i<cont-1;i++)
       {
           for(int j=0;j<cont-1-i;j++)
           {
               if(v[j+1].legajo<v[j].legajo)
               {
                  aux= v[j];
                  v[j]=v[j+1];
                  v[j+1]=aux;
               }
           }
       }
        fseek(f,0,SEEK_SET);
        fwrite(&v,cont*sizeof(alumno),1,f);
        cout<<"Se ha ordenado el archivo"<<endl;
        fclose(f);
    }else
    {
        cout<<"No se ha podido abrir el archivo"<<endl;
    }
    cout<<endl;
    return;
}

char mostrarMenu(void)
{
    cout<<"Ingrese 1 para agregar un alumno"<<endl;
    cout<<"Ingrese 2 para mostrar el archivo"<<endl;
    cout<<"Ingrese 3 para buscar por dni"<<endl;
    cout<<"Ingrese 4 para borrar logicamente un alumno"<<endl;
    cout<<"Ingrese 5 para deletear el archivo y reescribirlo sin los alumnos borrados"<<endl;
    cout<<"Ingrese 6 para mostrar a los alumnos no borrados"<<endl;
    cout<<"Ingrese 7 para mostrar el archivo nuevo"<<endl;
    cout<<"Ingrese 8 para ordenar el archivo"<<endl;
    cout<<"esc para salir"<<endl;
    char opcion;
    do
    {
        opcion=getch();
    }while((opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4') && (opcion!='5') && (opcion!='6') && (opcion!='7') && (opcion!='8') &&(opcion!=27));
    return opcion;
}

int main()
{
    alumno buscado;
    char opcion;
    do
    {
        opcion=mostrarMenu();
        switch(opcion)
        {
        case '1':
            guardarAlumno();
            break;
        case '2':
            mostrarTodo(NOMBREARCHIVO);
            break;
        case '3':
            buscarPorDni();
            break;
        case '4':
            borradoLogico();
            break;
        case '5':
            borrarArchivo();
            break;
        case '6':
            mostrarNoBorrados();
            break;
        case '7':
            mostrarTodo(NOMBREARCHIVOAUX);
            break;
        case '8':
            ordenarArchivo(NOMBREARCHIVO);
            break;
        }
    }while(opcion!=27);
    return 0;
}
