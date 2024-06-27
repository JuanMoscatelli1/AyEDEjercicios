#include <iostream>

using namespace std;

void modulo_proc(float &num)
{
    num = (-1)* num;
    return;
}

int main()
{
    float x = -20;
    cout << "|" << x << "| = ";
    modulo_proc(x);
    cout << x << endl;
    return 0;
}
