#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#define NOMBREARCHIVO "Asegurados.BAK"
#define ARCHIVO2 "Incidentes.BAK"
#define ARCHIVO3 "procesados.BAK"



using namespace std;

struct incidente{
    int numPoliza;
    int cIncidente;
    char fechaHora[14];
    char dni[11];
    char otroDni[11];
    char calle[20];
    int altura;
};

struct poliza{
    int nPoliza;
    char dni[11];
    char nombre[20];
    char apellido[20];
    char cuota;
    char patente[15];
    char activa;
    int incidentes;
    int borrado;
};

void ordenar()
{
poliza p;
poliza v[15];
int i=0;
FILE *f;
FILE *f2;
f = fopen(NOMBREARCHIVO, "rb+");
while(fread(&p,sizeof(struct poliza),1,f))
{
  v[i]=p;
  i++;
}

poliza aux;
for(int j=0;j<i-1;j++)
{
    for(int k=0;k<i-1;k++)
    {
        if (v[k+1].incidentes < v[k].incidentes)
        {
          aux = v[k];
          v[k]= v[k+1];
          v[k+1] = aux;
        }
    }
}
fseek(f,0,SEEK_SET);
fwrite(&v,i*sizeof(struct poliza),1,f);
fclose(f);
return;
}

void procesar(){
    FILE *f2;
    FILE *f3;
    FILE *fproc;
    int encontrado=0;
    poliza p;
    incidente i;
    if(f2 = fopen(ARCHIVO2, "rb"))
       {
           f3 = fopen(NOMBREARCHIVO,"rb+");
           fread(&i, sizeof(incidente),1,f2);
            while(!feof(f2))
                {
                    while(!encontrado && fread(&p,sizeof(struct poliza),1,f3) )
                    {
                        if(i.numPoliza == p.nPoliza)
                            {
                                encontrado = 1;
                                p.incidentes +=1;
                                fseek(f3,(-1)*sizeof(struct poliza), SEEK_CUR);
                                fwrite(&p,sizeof(struct poliza),1,f3);
                            }
                        if(EOF == true){encontrado = 1;}

                        fread(&i, sizeof(struct incidente), 1, f2);
                    }
                }
       }
    fproc=fopen(ARCHIVO3,"wb");
    fseek(f2,0,SEEK_SET);
    while(fread(&p,sizeof(struct incidente),1,f2))
          {
            fwrite(&p,sizeof(struct incidente),1,fproc);
          }

    fclose(f2);
    fclose(f3);
    fclose(fproc);
    remove(ARCHIVO2);
    cout<<"Se han procesado los incidentes"<<endl;
    return;
}

bool guardarIncidente(){
    FILE *f2;
    incidente i;
    if (f2 = fopen(ARCHIVO2,"ab")){
        cout<<"Ingrese el numero de poliza"<<endl;
        cin>>i.numPoliza;
        cout<<"Ingrese codigo de incidente: "<<endl;
        cin>>i.cIncidente;
        cout<<"Ingrese fecha y hora (AAAAMMDDHHMM): "<<endl;
        cin>>i.fechaHora;
        cout<<"Ingrese DNI del asegurado: "<<endl;
        cin>>i.dni;
        cout<<"Ingrese DNI del otro conductor: "<<endl;
        cin>>i.otroDni;
        cout<<"Ingrese Calle: "<<endl;
        cin>>i.calle;
        cout<<"Ingrese Altura: "<<endl;
        cin>>i.altura;

        fwrite(&i, sizeof(incidente),1,f2);
        fclose(f2);
        return true;
    }
    return false;
}

bool guardarPoliza(){
    FILE *f;
    poliza p;
    if (f = fopen(NOMBREARCHIVO,"ab")){
        cout<<"Ingrese numero de poliza: "<<endl;
        cin>>p.nPoliza;
        cout<<"Ingrese DNI: "<<endl;
        cin>>p.dni;
        cout<<"Ingrese nombre: "<<endl;
        cin>>p.nombre;
        cout<<"Ingrese apellido: "<<endl;
        cin>>p.apellido;
        cout<<"Tiene la cuota al dia (V/F): "<<endl;
        cin>>p.cuota;
        cout<<"Ingrese patente del auto: "<<endl;
        cin>>p.patente;
        cout<<"Poliza activa (V/F): "<<endl;
        cin>>p.activa;
        cout<<"Ingrese cantidad de incidentes: "<<endl;
        cin>>p.incidentes;
        fwrite(&p, sizeof(poliza),1,f);
        fclose(f);
        return true;
    }
    return false;
}

void borrar (char DNI[])
{

    FILE *f;
    int encontrado = 0;
    poliza p;
    if (f=fopen(NOMBREARCHIVO,"rb+"))
    {
        while(!encontrado && fread(&p,sizeof(poliza),1,f))
        {
            if (strcmp(DNI, p.dni)==0)
            {
                encontrado = 1;
                p.borrado = 1;
                fseek(f,(-1)*sizeof(poliza), SEEK_CUR);
                fwrite(&p,sizeof(poliza),1,f);
                cout<<"Se ha borrado la poliza exitosamente"<<endl;
            }
        }
        if (!encontrado)
            cout << "No se encontro la poliza a borrar." << endl;
        fclose(f);

    }
    return;
}

int mostrarTodo(){
    FILE *f;
    poliza p;
    if(f = fopen(NOMBREARCHIVO, "rb")){
        fread(&p, sizeof(poliza),1,f);
        while(!feof(f)){
            if(p.borrado==0){
            cout<<"\n*****DATOS DE LA POLIZA*****"<<endl;
            cout<<"Nro poliza: "<<p.nPoliza<<endl;
            cout<<"DNI: "<<p.dni<<endl;
            cout<<"Nombre: "<<p.nombre<<endl;
            cout<<"Apellido: "<<p.apellido<<endl;
            cout<<"Cuota Al Dia: "<<p.cuota<<endl;
            cout<<"Patente: "<<p.patente<<endl;
            cout<<"Activa: "<<p.activa<<endl;
            cout<<"Cdad Incidentes: "<<p.incidentes<<endl;
            }
            fread(&p, sizeof(struct poliza), 1, f);
        }
        fclose(f);
        return 1;
    }
    return 0;
}

int mostrarI(){
    FILE *f2;
    incidente i;
    if(f2 = fopen(ARCHIVO2, "rb")){
        fread(&i, sizeof(incidente),1,f2);
        while(!feof(f2)){
            cout<<"\n*****DATOS DEL INCIDENTE*****"<<endl;
            cout<<"Numero de poliza: "<<i.numPoliza<<endl;
            cout<<"Codigo de i: "<<i.cIncidente<<endl;
            cout<<"Fecha hora: "<<i.fechaHora<<endl;
            cout<<"DNI: "<<i.dni<<endl;
            cout<<"Otro dni: "<<i.otroDni<<endl;
            cout<<"Calle: "<<i.calle<<endl;
            cout<<"Altura: "<<i.altura<<endl;
            fread(&i, sizeof(struct incidente), 1, f2);
        }
        fclose(f2);
        return 1;
    }
    return 0;
}

int buscarporDNI(char DNI[]){
    FILE *f;
    int encontrado = 0;
    struct poliza p;
    if(f=fopen(NOMBREARCHIVO, "rb")){
        while(fread(&p,sizeof(struct poliza),1,f) && !encontrado){
            if(strcmp(DNI,p.dni)== 0){

                cout<<"\n*****DATOS DE LA POLIZA*****"<<endl;
                cout<<"Nro poliza: "<<p.nPoliza<<endl;
                cout<<"DNI: "<<p.dni<<endl;
                cout<<"Nombre: "<<p.nombre<<endl;
                cout<<"Apellido: "<<p.apellido<<endl;
                cout<<"Cuota Al Dia: "<<p.cuota<<endl;
                cout<<"Patente: "<<p.patente<<endl;
                cout<<"Activa: "<<p.activa<<endl;
                cout<<"Cdad Incidentes: "<<p.incidentes<<endl;
            }
            if(EOF == true){encontrado = 1;}
        }
        if(encontrado == 0){
            cout<<"No se ha encontrado la poliza"<<endl;
        }
            fclose(f);
            return 1;
    }
    return 0;
}

int buscarporPoliza(int nropoliza){
    FILE *f;
    int encontrado = 0;
    struct poliza p;
    if(f=fopen(NOMBREARCHIVO, "rb")){
        while(fread(&p,sizeof(struct poliza),1,f) && !encontrado){
            if(nropoliza==p.nPoliza){

                cout<<"\n*****DATOS DE LA POLIZA*****"<<endl;
                cout<<"Nro poliza: "<<p.nPoliza<<endl;
                cout<<"DNI: "<<p.dni<<endl;
                cout<<"Nombre: "<<p.nombre<<endl;
                cout<<"Apellido: "<<p.apellido<<endl;
                cout<<"Cuota Al Dia: "<<p.cuota<<endl;
                cout<<"Patente: "<<p.patente<<endl;
                cout<<"Activa: "<<p.activa<<endl;
                cout<<"Cdad Incidentes: "<<p.incidentes<<endl;
            }
            if(EOF == true){encontrado = 1;}
        }
        if(encontrado == 0)
            cout<<"No se ha encontrado la poliza"<<endl;
            fclose(f);
            return 1;
    }
    return 0;
}

void mostrarMenu(){
    cout<<"Ingrese una opcion: "<<endl;
    cout<<"1 - Agregar una nueva poliza"<<endl;
    cout<<"2 - Desactivar poliza "<<endl;
    cout<<"3 - Buscar poliza por dni"<<endl;
    cout<<"4 - Listar las polizas"<<endl;
    cout<<"5 - Borrado fisico"<<endl;
    cout<<"6 - Agregar incidente"<<endl;
    cout<<"7 - Mostrar incidentes"<<endl;
    cout<<"8 - Procesar incidente"<<endl;
    cout<<"9 - Ordenar polizas"<<endl;
    cout<<"ESC - Salir"<<endl;
}

int main()
{
    long cont=1;
    char opcion;
    char dnibuscado[11];
    int polizabuscada;

    do{
        mostrarMenu();
        do{
            opcion = getch();
        }
        while(opcion!=27 &&!(opcion>='1' && opcion<='9'));

    switch (opcion){
    case '1':
        if(guardarPoliza())
            cout<<"Se ha guardado la poliza"<<endl;
        else
            cout<<"Error al intentar guardar la poliza"<<endl;

        break;
    case '2':
        cout<<"Ingrese el DNI de la poliza a borrar"<<endl;
        cin>>dnibuscado;
        borrar(dnibuscado);

        break;
    case '3':
        char opcion3;

        cout<<"Buscas por DNI o nro de Poliza (D/P)"<<endl;
        opcion3=getch();
        if(opcion3=='D' || opcion3=='d' ){
            cout<<"Ingrese el DNI del asegurado: "; cin>>dnibuscado;
            if(!buscarporDNI(dnibuscado))
            cout<<"No se pudo abrir el archivo"<<endl;
        }
        if(opcion3=='P' || opcion3=='p' ){
            cout<<"Ingrese el nro de poliza del asegurado: "; cin>>polizabuscada;
            if(!buscarporPoliza(polizabuscada))
            cout<<"No se pudo abrir el archivo"<<endl;
        }



        break;
    case '4':
        if(!mostrarTodo())
            cout<<"No se pudo abrir el archivo"<<endl;

        break;
    case '5':
        FILE *faux;
        FILE *f;
        poliza p;
        faux = fopen("auxiliar","wb");
        if(f = fopen(NOMBREARCHIVO, "rb+")){
            while(fread(&p,sizeof(struct poliza),1,f)){
                if(!p.borrado){
                    fwrite(&p,sizeof(struct poliza),1,faux);
                }
            }
            fclose(f);
        }
        fclose(faux);
        if(!remove(NOMBREARCHIVO)){
            if(!rename("auxiliar",NOMBREARCHIVO)){
                cout<<"Archivo renombrado exitosamente"<<endl;
            }
            else{
                cout<<"No se pudo renombrar el archivo"<<endl;
            }
        }
        else{
            cout<<"No se pudo borrar el viejo archivo"<<endl;
        }

        break;
    case '6':
        char opcion2;

        do{
            cout<<"Agregue un incidente\n"<<endl;
            if(guardarIncidente())
            cout<<"Se ha guardado el incidente"<<endl;
        else
            cout<<"Error al intentar guardar el incidente"<<endl;
        cout<<"Continuar agregando incidentes (Y/N)"<<endl;
        opcion2 = getch();
        }
        while(opcion2 == 'Y' || opcion2 == 'y');

        break;
    case '7':
        if(!mostrarI())
            cout<<"No se pudo abrir el archivo"<<endl;
        break;
    case '8':
        procesar();
        break;
    case '9':
        ordenar();
        cout<<"Se ha ordenado el archivo de polizas"<<endl;
        break;
    }

    cout<<"\nPresione una tecla para continuar"<<endl;
    getch();
    system("cls");
    }
    while((int) opcion != 27);
    return 0;

}
