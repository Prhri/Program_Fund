#include<iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int max=abs(a)+abs(b)+abs(c);
    while(max!=a&&max!=b&&max!=c)
    {
        max--;
    }
    cout<<max;
}
