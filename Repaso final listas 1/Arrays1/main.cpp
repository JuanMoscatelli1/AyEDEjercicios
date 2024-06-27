#include <iostream>

using namespace std;

int main()
{
    int v[10];
    for(int i=0;i<10;i++)
    {
        cout<<"v["<<i<<"]: "<<endl;
        cin>>v[i];
    }
    cout<<"En orden inverso: "<<endl;
    for(int j=9;j>=0;j--)
    {
        cout<<v[j]<<"|";
    }
    return 0;
}
