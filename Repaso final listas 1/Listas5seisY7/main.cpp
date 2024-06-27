#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

struct materia
{
    char nombre[50];
    char fechaAprobacion[11];
    int legajo; /* para identificar d quien es */
    int nota;
    int libro;
    int folio;
};

struct alumno
{
    char nombre[50];
    char apellido[50];
    char dni[10];
    int legajo;
    int codigoCarrera;
};

struct nodoListaMateria
{
    materia info;
    nodoListaMateria *sgte;
};

struct nodoListaAlumno
{
    alumno info;
    nodoListaAlumno *sgte;
    nodoListaMateria *listaMaterias;

};

void cargarAlumnosAlArchivo(void)
{
    FILE *f;
    f = fopen("archivoalumnos.data","wb");
    alumno al;
    if(f)
    {
        strcpy(al.apellido,"Gomez");
        strcpy(al.nombre,"Ricardo");
        strcpy(al.dni,"348765");
        al.codigoCarrera=20;
        al.legajo=100;
        fwrite(&al,sizeof(alumno),1,f);

        strcpy(al.apellido,"Perez");
        strcpy(al.nombre,"Gustavo");
        strcpy(al.dni,"456781");
        al.codigoCarrera=21;
        al.legajo=200;
        fwrite(&al,sizeof(alumno),1,f);

        strcpy(al.apellido,"Martinez");
        strcpy(al.nombre,"Eduardo");
        strcpy(al.dni,"643597");
        al.codigoCarrera=22;
        al.legajo=300;
        fwrite(&al,sizeof(alumno),1,f);

        strcpy(al.apellido,"Benitez");
        strcpy(al.nombre,"Jorge");
        strcpy(al.dni,"576842");
        al.codigoCarrera=23;
        al.legajo=400;
        fwrite(&al,sizeof(alumno),1,f);

        cout<<"el archivo se ha cargado con exito(alumnos)"<<endl;
    }else
    {
        cout<<"no se ha podido cargar el archivo"<<endl;
    }
    fclose(f);
    return;

}

void cargarMateriasArchivo(void)
{
    FILE *f;
    f = fopen("archivomaterias.data","wb");
    materia mat;
    if(f)
    {
        strcpy(mat.nombre,"Algoritmos");
        strcpy(mat.fechaAprobacion,"01022020");
        mat.folio = 25;
        mat.libro = 48;
        mat.nota = 8;
        mat.legajo = 100;
        fwrite(&mat,sizeof(materia),1,f);

        strcpy(mat.nombre,"Algoritmos");
        strcpy(mat.fechaAprobacion,"01022020");
        mat.folio = 35;
        mat.libro = 77;
        mat.nota = 6;
        mat.legajo = 200;
        fwrite(&mat,sizeof(materia),1,f);

        strcpy(mat.nombre,"fisica1");
        strcpy(mat.fechaAprobacion,"03102020");
        mat.folio = 77;
        mat.libro = 95;
        mat.nota = 10;
        mat.legajo = 100;
        fwrite(&mat,sizeof(materia),1,f);

        strcpy(mat.nombre,"analisis1");
        strcpy(mat.fechaAprobacion,"26052019");
        mat.folio = 22;
        mat.libro = 13;
        mat.nota = 6;
        mat.legajo = 300;
        fwrite(&mat,sizeof(materia),1,f);

        cout<<"el archivo se ha cargado con exito(materias)"<<endl;
    }else
    {
        cout<<"no se ha podido cargar el archivo"<<endl;
    }
    fclose(f);
    return;

}

char mostrarMenu(void)
{
    cout<<"Ingrese una opcion"<<endl;
    cout<<"Presione 0 para cargar los archivos (resetea)"<<endl;
    cout<<"Presione 1 para buscar un alumno por legajo"<<endl;
    cout<<"Presione 2 para listar materias aprobadas (por legajo)"<<endl;
    cout<<"Presione 3 para listar el promedio (legajo)"<<endl;
    cout<<"Presione 4 para agregar un alumno"<<endl;
    cout<<"Presione 5 para agregar una materia a un alumno"<<endl;
    cout<<"Presione 6 para listar todos los alumnos"<<endl;
    cout<<"esc para salir"<<endl;
    char opcion;
    do
    {
        opcion = getch();
    }while((opcion!='0') && (opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4') && (opcion!='5') && (opcion!='6') && (opcion!=27));
    return opcion;
}

void borrarListaMaterias(nodoListaMateria *&lista)
{
    nodoListaMateria *aux;
    nodoListaMateria *anterior;
    while(lista!=NULL)
    {
        anterior=NULL;
        aux=lista;
        while(aux && aux->sgte)
        {
            anterior=aux;
            aux=aux->sgte;
        }
        if(aux)
        {
            delete aux;
            if(anterior!=NULL)
                anterior->sgte=NULL;
            else
                lista =NULL;
        }
    }
    return;
}

void borrarListaAlumno(nodoListaAlumno *&lista)
{
    nodoListaAlumno *aux;
    nodoListaAlumno *anterior;
    while(lista!=NULL)
    {
        anterior=NULL;
        aux=lista;
        while(aux && aux->sgte)
        {
            anterior=aux;
            aux=aux->sgte;
        }
        if(aux)
        {
            borrarListaMaterias(aux->listaMaterias);
            delete aux;
            if(anterior!=NULL)
                anterior->sgte=NULL;
            else
                lista =NULL;
        }
    }
    return;
}

void insertarListaAlumnos(nodoListaAlumno *&lista,alumno a)
{
    nodoListaAlumno *nuevo = new nodoListaAlumno();
    nuevo->info =a;
    nuevo->listaMaterias=NULL;
    if(lista!=NULL)
    {
        nuevo->sgte = lista->sgte;
        lista->sgte = nuevo;
    }else
    {
        nuevo->sgte=lista;
        lista=nuevo;
    }

    return;
}

nodoListaAlumno *buscarAlumnoPorLegajo(nodoListaAlumno *lista,int legajo)
{
    while(lista && (lista->info.legajo!=legajo))
    {
        lista=lista->sgte;
    }
    return lista;
}

void insertarListaMaterias(nodoListaMateria *&lista,materia m)
{
    nodoListaMateria *nuevo = new nodoListaMateria();
    nuevo->info =m;
    if(lista!=NULL)
    {
        nuevo->sgte = lista->sgte;
        lista->sgte = nuevo;
    }
    else
    {
        nuevo->sgte=lista;
        lista=nuevo;
    }
    return;
}

void armarLista(nodoListaAlumno *&lista)
{
    FILE *f;
    alumno a;
    materia m;

    f=fopen("archivoalumnos.data","rb");
    while(fread(&a,sizeof(alumno),1,f))
    {
        insertarListaAlumnos(lista,a);
    }
    fclose(f);
    f=fopen("archivomaterias.data","rb");
    while(fread(&m,sizeof(materia),1,f))
    {
        nodoListaAlumno *aux = buscarAlumnoPorLegajo(lista,m.legajo);
        if(aux)
        {
          insertarListaMaterias(aux->listaMaterias,m);
        }

    }
    fclose(f);
    return;
}

void mostrarAlumno(alumno a)
{
    cout<<"DATOS ALUMNO:"<<endl;
    cout<<"Nombre: "<<a.nombre<<endl;
    cout<<"Apellido: "<<a.apellido<<endl;
    cout<<"Codigo de la carrera: "<<a.codigoCarrera<<endl;
    cout<<"DNI: "<<a.dni<<endl;
    cout<<"Legajo: "<<a.legajo<<endl;
    return;
}

void mostrarListaMaterias(nodoListaMateria *lista)
{
    while(lista)
    {
        cout<<"Nota: "<<lista->info.nota<<endl;
        cout<<"Nombre: "<<lista->info.nombre<<endl;
        cout<<"Libro: "<<lista->info.libro<<endl;
        cout<<"Legajo: "<<lista->info.legajo<<endl;
        cout<<"Folio: "<<lista->info.folio<<endl;
        cout<<"Fecha de aprobacion: "<<lista->info.fechaAprobacion<<endl;
        lista=lista->sgte;

    }
    return;
}

nodoListaAlumno *obtenerUltimo(nodoListaAlumno *lista)
{
    if(lista)
    {
       while(lista)
       {
           lista=lista->sgte;
       }
    }
    return lista;
}

void insertarListaAlumnosAlFinal(nodoListaAlumno *&lista,alumno a)
{
    nodoListaAlumno *aux=obtenerUltimo(lista);
    if(aux)
    {
        insertarListaAlumnos(aux,a);
    }else
    {
        insertarListaAlumnos(lista,a);
    }
    return;
}

void guardarEnArchivo(nodoListaAlumno *lista)
{
    FILE* falumnos;
    FILE* fmaterias;
    nodoListaAlumno *listaAlum =NULL;
    nodoListaMateria *listaMat =NULL;
    if(falumnos=fopen("archivoalumnos","wb"))
    {
        if(fmaterias=fopen("archivomaterias","wb"))
        {
            listaAlum = lista;
            while(listaAlum)
            {
                fwrite(&(listaAlum->info),sizeof(alumno),1,falumnos);
                listaMat=listaAlum->listaMaterias;
                while(listaMat)
                {
                    fwrite(&(listaMat->info),sizeof(materia),1,fmaterias);
                    listaMat=listaMat->sgte;
                }
                listaAlum=listaAlum->sgte;
            }
            fclose(fmaterias);
        }
        fclose(falumnos);
    }
    return;
}

int main()
{
    char opcion;
    nodoListaAlumno *lista =NULL;
    nodoListaAlumno *aux =NULL;
    armarLista(lista);
    int legajo;
    do
    {
        opcion = mostrarMenu();
        switch(opcion)
        {
        case '0':

                borrarListaAlumno(lista);
                cargarAlumnosAlArchivo();
                cargarMateriasArchivo();
                armarLista(lista);

            break;
        case '1':
                cout<<"ingrese legajo"<<endl;
                cin>>legajo;
                aux = buscarAlumnoPorLegajo(lista,legajo);
                if(aux)
                {
                    mostrarAlumno(aux->info);
                }else
                {
                    cout<<"No se ha podido encontrar"<<endl;
                }
             break;
        case '2':
                cout<<"ingrese legajo"<<endl;
                cin>>legajo;
                aux= buscarAlumnoPorLegajo(lista,legajo);
                if(aux)
                {
                    mostrarListaMaterias(aux->listaMaterias);
                }
                else
                    cout<<"No hay materias"<<endl;
                break;
        case '3':
                cout<<"Ingrese legajo"<<endl;
                cin>>legajo;
                aux= buscarAlumnoPorLegajo(lista,legajo);
                if(aux)
                {
                    nodoListaMateria *materiasPromedio = aux->listaMaterias;
                    int acum=0;
                    int cont=0;
                    while(materiasPromedio)
                    {
                        acum += materiasPromedio->info.nota;
                        cont++;
                        materiasPromedio=materiasPromedio->sgte;
                    }
                    if(cont>0)

                        cout<<"El promedio es: "<<acum/cont<<endl;
                    else
                        cout<<"No tiene materias"<<endl;
                }else
                    cout<<"No existe el alumno"<<endl;
                break;
        case '4':
                alumno alumnoNuevo;
                cout<<"Ingrese el nombre del alumno"<<endl;
                cin>>alumnoNuevo.nombre;
                cout<<"Ingrese el apellido del alumno"<<endl;
                cin>>alumnoNuevo.apellido;
                cout<<"Ingrese legajo"<<endl;
                cin>>alumnoNuevo.legajo;
                cout<<"Ingrese codigo de carrera"<<endl;
                cin>>alumnoNuevo.codigoCarrera;
                cout<<"Ingrese dni"<<endl;
                cin>>alumnoNuevo.dni;
                insertarListaAlumnosAlFinal(lista,alumnoNuevo);
                cout<<"Se ha ingresado al alumno"<<endl;

                break;
        case '5':
                materia materiaNueva;
                cout<<"Ingrese legajo del alumno"<<endl;
                cin>>legajo;
                aux=buscarAlumnoPorLegajo(lista,legajo);
                if(aux)
                {
                cout<<"Ingrese el nombre de la materia (SIN ESPACIOS D:)"<<endl;
                cin>>materiaNueva.nombre;
                cout<<"Ingrese la fecha de aprobacion de la materia"<<endl;
                cin>>materiaNueva.fechaAprobacion;
                cout<<"Ingrese el folio de la materia"<<endl;
                cin>>materiaNueva.folio;
                cout<<"Ingrese la nota de la materia"<<endl;
                cin>>materiaNueva.nota;
                cout<<"Ingrese el libro de la materia"<<endl;
                cin>>materiaNueva.libro;
                materiaNueva.legajo=legajo;
                insertarListaMaterias(aux->listaMaterias,materiaNueva);
                cout<<"Se ha insertado la materia"<<endl;
                }else
                    cout<<"No se ha podido insertar"<<endl;

                break;
        case '6':

                aux = lista;
                if(aux)
                {
                    cout<<"tiene algo"<<endl;
                }else
                {

                    cout<<"esta vacia :("<<endl;
                }
                while(aux)
                {
                    mostrarAlumno(aux->info);
                    aux=aux->sgte;
                }

            break;
        }


    }while(opcion!=27);
    guardarEnArchivo(lista);
    borrarListaAlumno(lista);
    return 0;
}
