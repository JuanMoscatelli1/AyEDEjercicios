#include <iostream>
#include <conio.h>

using namespace std;
/* no funca */
int main()
{
    char v[20];
    char c;
    char cont=0;
    cout<<"Ingrese caracteres y corte con /"<<endl;
    cin>>c;
    while(c!='/')
    {
        v[cont]=c;
        cont++;
        cin>>c;
    }
    cout<<"La palabra al reves: "<<endl;
    for(int i=cont-1;i>=0;i--)
    {
        cout<<v[cont]<<"|";
    }
    return 0;
}
