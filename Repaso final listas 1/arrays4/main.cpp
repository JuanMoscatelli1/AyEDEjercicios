#include <iostream>
#include <conio.h>

using namespace std;

void invertir(int v[],int pos,int tam)
{
    int aux;
    if(pos<tam/2)
    {
        aux=v[pos];
        v[pos]=v[tam-1-pos];
        v[tam-1-pos]=aux;
        invertir(v,pos+1,tam);
    }
    return;
}

int main()
{
    int v[]={4,3,7,6,9,1};
    invertir(v,0,6);
     for (int i =0; i < 6; i++)
            cout << "v[" << i << "]= " << v[i] << endl;
    return 0;
}
