/*********************************** TABLAS Y MATRICES***********************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#define M 4
#define N 5
#define P 3
using namespace std;


void cargar_tabla(int t[][N])
{
    //cargo los datos de la tabla con algunos valores
    //vamos a generar números random, primero inicializamos el random:
    srand(time(0));
    for (int i=0; i< M; i++)
    {
        for (int j=0; j < N; j++)
        {
            t[i][j]= rand()%100;
        }
    }
    return;
}

void mostrar_tabla(int const t[][N])
{
    for (int i=0; i< M; i++)
    {
        for (int j=0; j < N; j++)
        {
            cout << t[i][j] << "\t\t";
        }
        cout << endl << endl;
    }
    cout << "Fin de la tabla, presione una tecla para finalizar." << endl;
    getch();
    return;
}


void cargar_matriz(int m[][N][P])
{
    //cargo los datos de la tabla con algunos valores
    //vamos a generar números random, primero inicializamos el random:
    srand(time(0));
    for(int k=0; k< P; k++)
    {
        for (int i=0; i< M; i++)
        {
            for (int j=0; j < N; j++)
            {
                m[i][j][k]= rand()%100;
            }
        }
    }
    return;
}

void mostrar_matriz(int const m[][N][P])
{
    for(int k=0; k< P; k++)
    {
        for (int i=0; i< M; i++)
        {
            for (int j=0; j < N; j++)
            {
                cout << m[i][j][k] << "\t\t";
            }
            cout << endl << endl;
        }
        if (k < P-1)
            cout << "Presione una tecla para ver la siguiente 'feta'" << endl;
        else
            cout << "Fin de la matriz, presione una tecla para finalizar." << endl;
        getch();
    }
    return;
}


int main()
{
    int tabla [M][N];
    int matriz[M][N][P];
    //Carga con números aleatorios:
    cargar_tabla(tabla);
    cargar_matriz(matriz);

    cout << "********************* Mostramos la tabla *********************" << endl;
    mostrar_tabla(tabla);
    cout << "********************* Mostramos la matriz *********************" << endl;
    mostrar_matriz(matriz);
    return 0;


}
