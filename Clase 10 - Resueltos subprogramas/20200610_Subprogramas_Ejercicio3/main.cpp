#include <iostream>

using namespace std;

void factorialProcedimiento(short,long&);
long factorialFuncion(short);
long  factorial_recursivo(short);

int main() {
    short numero;
    long resultado;

    cout << "Ingrese un numero:" << endl;
    cin >> numero;
    //Invocación de procedimiento:
    cout << "======= Invocamos el procedimieto =======" << endl;
    factorialProcedimiento(numero,resultado);
    cout << "factorialProcedimiento:"<< resultado << endl;
    //Invocación como función repetitiva:
    cout << "======= Invocamos la funcion repetitiva =======" << endl;
    cout << "factorialFuncion:" << factorialFuncion(numero) << endl;
    //Invocación como función recursiva:
    cout << "======= Invocamos la funcion recursiva =======" << endl;
    cout << "factorial_recursivo:" << factorial_recursivo(numero)<< endl;
    return 0;
}

/* resolución del ejercicio 3 con repetitivas como procedimiento */
void factorialProcedimiento(short nro,long &resultado){
    resultado = 1;
    for(int i=1;i<=nro;i++)
    {
        resultado*=i;
    }
    return;
}


/* resolución del ejercicio 3 con repetitivas como procedimiento */
long factorialFuncion(short n){
    long fact=1;
    for(int i=1;i<=n;i++)
        fact*=i;
    return fact;

}

/* resolución del ejercicio 3 de manera recursiva */
long factorial_recursivo(short n)
{
    if (n <= 1)
        return 1;
    return n * factorial_recursivo(n-1);

}
