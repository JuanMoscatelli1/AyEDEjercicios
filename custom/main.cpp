#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#define NOMBREARCHIVO "Asegurados.BAK"
#define ARCHIVO2 "procesados.BAK"

using namespace std;
struct poliza
{
    int nPoliza;
    char dni[11];
};
int main()
{
    poliza p[1];
    poliza o[1];
    p[0].nPoliza=15;
    cout<<"ingrese dni"<<endl;
    cin>>p[0].dni;
    cout<<"numero: "<<p[0].nPoliza<<endl;
    cout<<"dni: "<<p[0].dni<<endl;
    o[0]=p[0];
    cout<<"numero o: "<<o[0].nPoliza<<endl;
    cout<<"dni o: "<<o[0].dni<<endl;
}
