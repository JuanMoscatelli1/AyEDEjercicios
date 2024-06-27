#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define LONG 5
#define VACIO -10000

//const int vacio =-1000;
typedef int  mi_tdato;
using namespace std;

//Inicializa el vecto con valores vacíos
void inicializar(mi_tdato v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
            v[i] = VACIO;
    }
    return;
}

//Muestra el vector por pantalla
void mostrar(const mi_tdato v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
            cout << "v[" << i << "] = " << v[i] << endl;
    }
    //v[2] = 20;
    return;
}

//Copia dos vectores
void copiar(const mi_tdato origen[], mi_tdato destino[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
            destino[i] = origen[i];
    }
    return;
}

/* Función insertar: Recibe por parámetros el dato a insertar y el vector.
Intenta insertarlo en el primer lugar que encuentre vacío, si lo hace devuelve
cero, si el vector está lleno devuelve código de error= 1 */
int insertar(mi_tdato dato, mi_tdato v[], int tam)
{
    int i = 0;
    int error=0;
    while (i< tam && v[i]!=VACIO)
        i++;
    if (i < tam)
        v[i] = dato;
    else
        error = 1;
    return error;
}

int cantElementos(const mi_tdato vec[], int tam)
{
    int i = 0;
    while ( i < tam && vec[i]!= VACIO)
        i++;
    return i;

}

/*Ordenamiento por burbujeo mejorado,
Considera las posiciones vacías al final
*/
void burbuja(mi_tdato v[], int tam)
{
    mi_tdato aux;
    int qelementos = cantElementos(v, tam);
    for (int i = 0; i < qelementos - 1; i++)
    {
       for (int j = 0; j < qelementos - 1 -i; j++)
       {
           if (v[j+1] < v[j])
           {
               aux = v[j];
               v[j] = v[j+1];
               v[j+1] = aux;
           }
       }
    }
    return;
}

/* busquedaSecuencial:
Devuelve -1 si no se encuentra el valor,
caso contrario devuelve la posición del vector donde está el valor buscado */
int busquedaSecuencial(const mi_tdato v[], int buscado, int tam)
{
    int i= 0;
    int posbuscado = -1;
    while (i< tam && posbuscado==(-1) )
    {
        if (v[i]==buscado)
        {
            posbuscado = i;
        }
        i++;
    }
    return posbuscado;
}

int busquedaBinaria(const mi_tdato vec[], mi_tdato clave, int tam)
{
  bool encontrado = false;
  int Iarriba = cantElementos(vec, tam)-1;
  int Iabajo = 0;
  int Icentro;
  int result = -1;
  while (Iabajo <= Iarriba && !encontrado)
  {
      Icentro = (Iarriba + Iabajo)/2;
      cout << "Primero = " << Iabajo << endl;
      cout << "Ultimo = " << Iarriba << endl;
      cout << "Centro = " << Icentro << endl;
      cout << "****************"  << endl;
      if (vec[Icentro] == clave)
      {
          result= Icentro;
          encontrado= true;
      }
      else
      {
        if (clave < vec[Icentro])
            Iarriba=Icentro-1;
        else
            Iabajo=Icentro+1;
      }
  }
  return result; // si no encontrado devuelve -1
}


void mostrarmenu()
{
    cout << "Ingrese una opción:" << endl;
    cout << "a - Inicializar vector" << endl;
    cout << "b - Ingresar un valor" << endl;
    cout << "c - Mostrar vector" << endl;
    cout << "d - Copiar vector" << endl;
    cout << "e - Ordenar vector" << endl;
    cout << "f - Indicar cantidad de elementos" << endl;
    cout << "g - Buscar elemento (binaria)" << endl;
    cout << "h - Buscar elemento (secuencial)" << endl;
    cout << "Esc - Salir" << endl;
}



int main()
{
    mi_tdato vec[LONG];
    mi_tdato vec2[LONG];
    mi_tdato dato;

    char opcion;
    do
    {
        mostrarmenu();
        do
        {
                opcion=getch();
        } while (opcion!=27 &&
                 !(opcion>='A' && opcion<='H') &&
                 !(opcion>='a' && opcion<='h')
                 );

        switch (opcion)
        {
            case 'a':
            case 'A':
                    inicializar(vec, LONG);
                break;
            case 'b':
            case 'B':
                    cout << "Ingrese el dato a almacenar" << endl;
                    cin >> dato;
                    if (insertar(dato, vec, LONG))
                        cout << "Error al intentar ingresar el dato. Vector lleno" << endl;
                    else
                        cout << "Dato ingresado correctamnte" << endl;

                break;
            case 'c':
            case 'C':
                    mostrar(vec, LONG);
                break;
            case 'd':
            case 'D':
                    /*aunque no tiene mucho sentido (porque vec2 no se
                    vuelve a utilizar, esta línea copia vec en vec2) */
                    copiar(vec, vec2, LONG);
                    cout << "Elementos de vec2:" << endl;
                    mostrar(vec2, LONG);
                break;
            case 'e':
            case 'E':
                    burbuja(vec, LONG);
                break;
            case 'f':
            case 'F':
                    cout << "La cantidad de elementos es " << cantElementos(vec, LONG) << endl;
                break;
            case 'g':
            case 'G':
                    cout << "Ingrese el elemento a buscar (BUSQ. BIN.): " << endl;
                    cin >> dato;
                    int posicion;
                    burbuja(vec, LONG);
                    posicion = busquedaBinaria(vec, dato,LONG);
                    if (posicion != -1)
                        cout << "El elemento se encuentra en la posicion: " << posicion << endl;
                    else
                        cout << "No se encuentra el elemento.";
                break;
            case 'h':
            case 'H':
                    cout << "Ingrese el elemento a buscar (BUSQ. SECUENCIAL): " << endl;
                    cin >> dato;
                    posicion = busquedaSecuencial(vec, dato,LONG);
                    if (posicion != -1)
                        cout << "El elemento se encuentra en la posicion: " << posicion << endl;
                    else
                        cout << "No se encuentra el elemento.";
                break;
        }
        cout << "Presione una tecla para continuar." << endl;
        getch();
        //system("c:\\ayed2014\\x.docx");
        system("cls");
    } while (opcion != 27); //27 es el código ascii de la tecla Esc. Tengo que convertirlo a int para obtener su código en tabla
    return 0;
}
