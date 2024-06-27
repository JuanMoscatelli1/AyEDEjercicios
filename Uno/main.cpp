#include <iostream>
#include <conio.h>
using namespace std;

void unsubp(int x[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        if ((x[i]>0 && i%2==0) || !x[i])
            x[i] = 1;
    }
    return;
}

int main()
{
int u[6] = {0,5,3};
unsubp(u,6);
for (int i=0;i<6;i++)
    cout<<u[i]<<"; ";
return 0;
}
