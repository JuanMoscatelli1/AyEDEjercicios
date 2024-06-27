#include <iostream>
#include <conio.h>
#include <cmath>
#include <stdlib.h>
#include <ctime>
using namespace std;

void apareo(int v1[],int v2[],int vr[],int tam1,int tam2)
{
    int i=0,j=0,k=0;
    while(i<5&&j<3)
    {
        if(v1[i]<v2[j])
        {
            vr[k]=v1[i];
            i++;
        }
       else
        {
            vr[k]=v2[j];
            j++;
        }
        k++;
    }
    for(int c=i;c<5;c++)
    {
        vr[k]=v1[c];
        k++;
    }
    for(int c=j;c<3;c++)
    {
        vr[k]=v2[c];
        k++;
    }
    return;
}

void cargartabla(int t[6][5])
{

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<5;j++)
        {
            t[i][j]= j+3;
        }
    }
   return;
}
void fusion(int t[6][5],int v[30])
{
    int cont=0;
   for(int i=0;i<6;i++)
    {
        for(int j=0;j<5;j++)
        {
            v[cont]=t[i][j];
            cont++;
        }
    }
}
void burbuja(int v[30])
{
    int aux;
    for (int i = 0; i < 30 - 1; i++)
    {
       for (int j = 0; j < 30 - 1 -i; j++)
       {
           if (v[j+1] < v[j])
           {
               aux = v[j];
               v[j] = v[j+1];
               v[j+1] = aux;
           }
       }
    }
}
void mostrartabla(int t[6][5])
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<t[i][j]<<"\t\t";
        }
        cout<<endl<<endl;
    }
}
int main()
{
int t[6][5];
cargartabla(t);
mostrartabla(t);
int v[30];
fusion(t,v);
burbuja(v);

for(int i=0;i<30;i++)
{
    cout<<v[i]<<",";
}
return 0;
}
