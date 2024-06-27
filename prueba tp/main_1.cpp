#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#define NOMBREARCHIVO "Asegurados.BAK"
#define ARCHIVO2 "procesados.BAK"

//Falta: chequear incidentes y ver si algun dni es igual a uno de las polizas
//en tal caso, aumentar la cantidad de incidentes en la poliza
//Despues ordenar las polizas por cantidad de incidentes

using namespace std;

struct incidente{
    int lote;
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
    bool borrado;
};

bool guardarIncidente(int cont){
    FILE *f2;
    incidente i;
    if (f2 = fopen(ARCHIVO2,"ab")){
        i.lote = cont;
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

int borrar (char DNI[])
{
    // Aca hacemos un borrado logico
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
                p.borrado = true;
                fseek(f,(-1)*sizeof(poliza), SEEK_CUR);// atencion a esto, aca borro el encontrado, sin esto elimina al siguiente
                //busca el registro desde donde esta el cursor y lo manda para atras
                fwrite(&p,sizeof(poliza),1,f);
            }
        }
        if (encontrado == 0)
            cout << "No se encontro la poliza a borrar." << endl;
        fclose(f);
        return 1;
    }
    return 0;
}

int mostrarTodo(){
    FILE *f;
    poliza p;
    if(f = fopen(NOMBREARCHIVO, "rb")){
        fread(&p, sizeof(poliza),1,f);
        while(!feof(f)){
            cout<<"\n*****DATOS DE LA POLIZA*****"<<endl;
            cout<<"Nro poliza: "<<p.nPoliza<<endl;
            cout<<"DNI: "<<p.dni<<endl;
            cout<<"Nombre: "<<p.nombre<<endl;
            cout<<"Apellido: "<<p.apellido<<endl;
            cout<<"Cuota Al Dia: "<<p.cuota<<endl;
            cout<<"Patente: "<<p.patente<<endl;
            cout<<"Activa: "<<p.activa<<endl;
            cout<<"Cdad Incidentes: "<<p.incidentes<<endl;
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
            cout<<"Lote ["<<i.lote<<"]"<<endl;
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
            if(EOF == true){encontrado = 1;}// esto es para que siga buscando polizas de un dni hasta el final
        }
        if(encontrado == 0)
            cout<<"No se ha encontrado la poliza"<<endl;
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
            if(EOF == true){encontrado = 1;}// esto es para que siga buscando polizas de un dni hasta el final
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
    cout<<"6 - Agregar incidente en un lote"<<endl;
    cout<<"7 - Mostrar incidentes"<<endl;
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
        //esto de abajo tira error
        /*
        FILE *f2;
        incidente i;

        if(f = fopen(ARCHIVO2, "rb")){
            fseek(f2,sizeof(incidente)*(-1),SEEK_END);
            fread(&i, sizeof(incidente),1,f2);
            cont=i.lote + 1;
        }
        */
        cout<<"\n*****LOTE "<<cont<<"*****"<<endl;

        do{
            cout<<"Agregue un incidente\n"<<endl;
            if(guardarIncidente(cont))
            cout<<"Se ha guardado el incidente"<<endl;
        else
            cout<<"Error al intentar guardar el incidente"<<endl;
        cout<<"Continuar agregando incidentes en este lote? (Y/N)"<<endl;
        opcion2 = getch();
        }
        while(opcion2 == 'Y' || opcion2 == 'y');

        cont++;

        break;
    case '7':
        if(!mostrarI())
            cout<<"No se pudo abrir el archivo"<<endl;


    }

    cout<<"\nPresione una tecla para continuar"<<endl;
    getch();
    system("cls");
    }
    while((int) opcion != 27);
    return 0;

}
