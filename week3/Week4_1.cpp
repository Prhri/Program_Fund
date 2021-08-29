#include<iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int min=-abs(a)-abs(b)-abs(c);
    while(min!=a&&min!=b&&min!=c)
    {
        min++;
    }
    cout<<min;
}