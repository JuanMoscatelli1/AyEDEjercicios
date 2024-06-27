#include <iostream>
#include <conio.h>

using namespace std;

int sumar(int n1, int n2)
{
    return n1 + n2;
}

int restar(int n1, int n2)
{
    return n1 - n2;
}


int multiplicar(int n1, int n2)
{
    return n1 * n2;
}


int dividir (int n1, int n2, bool &error)
{
    if (n2 != 0)
    {
        error = false;
        return n1/n2;
    }
    error = true;
    return 0;
}

char leerOpcion(void)
{
    char c;
    cout << "Ingrese una opción:" << endl;
    cout << "a - Sumar " << endl;
    cout << "b - Restar " << endl;
    cout << "c - Multiplicar " << endl;
    cout << "d - Dividir " << endl;
    cout << "Esc - Salir" << endl;
    do {
        c = getch();
    } while (  c != 'a' && c != 'A' &&
             c != 'b'&& c != 'B'  &&
             c !='c' && c != 'C' &&
             c != 'd' && c != 'D' &&
             c != 27   );
    return c;
}


int main()
{
    setlocale(LC_ALL, "");
    char opcion;
    int n1,n2, resultado;
    bool err;
    cout << "Ingrese dos valores enteros:" << endl;
    cin >> n1 >> n2;
    do
    {
        opcion = leerOpcion();
        switch(opcion)
        {
            case 'a':
            case 'A':
                cout << "El resultado de la suma es: " << sumar(n1,n2) << endl;
            break;
            case 'b':
            case 'B':
                cout << "El resultado de la resta es: " << restar(n1,n2) << endl;
            break;
            case 'c':
            case 'C':
                cout << "El resultado de la multiplicación es: " << multiplicar(n1,n2) << endl;
            break;
            case 'd':
            case 'D':
                resultado= dividir(n1,n2, err);
                if (!err)
                    cout << "El resultado de la división es: " << resultado << endl;
                else
                    cout << "Error: división por cero" << endl;
            break;
        }
    }while (opcion!=27);
    return 0;
}
