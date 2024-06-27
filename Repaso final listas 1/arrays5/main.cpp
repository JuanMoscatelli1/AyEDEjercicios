#include <iostream>

using namespace std;

void sumarVectores(int v1[],int v2[],int v3[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        v3[i]=v1[i]+v2[i];
    }
    return;
}

int productoEscalar(int v1[],int v2[],int tam)
{
    int acum;
    for(int i=0;i<tam;i++)
    {
        acum+= v1[i]*v2[i];
    }
    return acum;
}

int main()
{
    int v1[10]={1,2,3,4,5};
    int v2[10]={6,7,8,9,10};
    int tam;
    int v3[10];
    cout<<"Ingrese el tamanio(5)"<<endl;
    cin>>tam;
    sumarVectores(v1,v2,v3,tam);
    cout<<"La suma es: "<<endl;
    for(int i=0;i<tam;i++)
    {
        cout<<v3[i]<<"|";
    }
    cout<<endl;
    int prodEsc;
    prodEsc=productoEscalar(v1,v2,tam);
    cout<<"El producto escalar es: "<<prodEsc<<endl;


    return 0;
}
