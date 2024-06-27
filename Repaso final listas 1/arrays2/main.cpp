#include <iostream>

using namespace std;

int mayor(int v[],int tam)
{
    int masGrande=v[0];
    for(int i=1;i<tam;i++)
    {
        if(v[i]>masGrande)
        {
            masGrande = v[i];
        }
    }
    return masGrande;
}

int menor(int v[],int tam)
{
    int masChico=v[0];
    for(int i=1;i<tam;i++)
    {
        if(v[i]<masChico)
        {
            masChico= v[i];
        }
    }
    return masChico;
}

float promedio(int v[],int tam)
{
    int acum=0;
    for(int i=0;i<tam;i++)
    {
        acum+=v[i];
    }
    return acum/tam;
}

int masProximo(int v[],int tam)
{
        float promedioNum=(promedio(v,tam));
        float distanciaAMasCercano=abs(v[0]-promedioNum);
        int masCercano=v[0];
        for(int i=0;i<tam;i++)
        {
            if(abs(v[i]-promedioNum)<distanciaAMasCercano)
            {
                masCercano=v[i];
                distanciaAMasCercano=abs(v[i]-promedioNum);
            }
        }
        return masCercano;

}

int main()
{
    int v[]={2,3,4,1,5,6,7,8,9,10,11,12,13,15,14};
    cout<<"El mayor es: "<<mayor(v,15)<<endl;
    cout<<"El menor es: "<<menor(v,15)<<endl;
    cout<<"El promedio es: "<<promedio(v,15)<<endl;
    cout<<"El mas proximo al promedio es: "<<masProximo(v,15)<<endl;
    return 0;
}
