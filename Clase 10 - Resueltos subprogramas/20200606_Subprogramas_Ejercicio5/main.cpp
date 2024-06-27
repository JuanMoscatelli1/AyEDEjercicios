#include <iostream>
#include <math.h>

using namespace std;


bool resolver_cuadratico(float a, float b, float c, float &r1, float &r2)
{
    if (b*b - 4 * a *c > 0)
    {
        r1 = (-b + pow( b*b - 4 * a *c, 0.5)) / (2*a);
        r2 = (-b - pow( b*b - 4 * a *c, 0.5)) / (2*a);
        return true;
    }
    return false;
}

int main()
{
    float  x1, x2;
    if (resolver_cuadratico(10,4,-2,x1,x2))
        cout << "Las raíces son r1: " << x1 << "y r2: " << x2 << endl;
    else
        cout << "Las raices no son reales." << endl;


    resolver_cuadratico(3,19,-20,y1,y2)
    return 0;
}
