#include <iostream>
#include <stdio.h>
#include <conio.h>
#define RUTA_ARCHIVO "archivoej.data"
using namespace std;

void insertarValor(void)
{
    FILE* f;
    int cant;
    int valor;
    cout<<"Ingrese la cantidad d numeros a agregar"<<endl;
    cin>>cant;
    if(f=fopen(RUTA_ARCHIVO,"ab"))
    {
        for(int i=1;i<=cant;i++)
        {
            cout<<"Ingrese un valor"<<endl;
            cin>>valor;
            fwrite(&valor,sizeof(int),1,f);
        }
        fclose(f);
        cout<<"Se han agregado los valores :)"<<endl;
        return;
    }else
    cout<<"Error"<<endl;
    return;
}

void mostrarArchivo(void)
{
    cout<<"Numeros: "<<endl;
    FILE *f;
    int aMostrar;
    if(f=fopen(RUTA_ARCHIVO,"rb"))
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

void modificarValor(void)
{
        int pos,valor;
        cout<<"Ingrese la posicion que desea cambiar"<<endl;
        cin>>pos;

        FILE *f;
        if(f=fopen(RUTA_ARCHIVO,"rb+"))
        {
            cout<<"Ingrese el nuevo valore"<<endl;
            cin>>valor;
            fseek(f,sizeof(int)*(pos-1),SEEK_SET);
            fwrite(&valor,sizeof(int),1,f);
            cout<<"Se ha cambiado el valor"<<endl;
        }
        fclose(f);
        return;
}

char mostrarMenu(void)
{
    cout<<"Ingrese 1 para agregar un valor"<<endl;
    cout<<"Ingrese 2 para modificar un valor"<<endl;
    cout<<"Ingrese 3 para mostrar todo"<<endl;
    char opcion;
    do
    {
         opcion = getch();
    }while((opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!=27));
    return opcion;
}

int main()
{
    char opcion;
    do
    {
        opcion = mostrarMenu();
        switch(opcion)
        {
            case '1':
                insertarValor();
                break;
            case '2':
                modificarValor();
                break;
            case '3':
                mostrarArchivo();
                break;

        }
    }while(opcion!=27);
    return 0;
}
