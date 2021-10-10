#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[4];
    int even=0;
    for(int i=0;i<4;i++)
    {
        cin>>a[i];
        if(a[i]%2==0)
            even++;
    }
    cout<<even;
    return 0;
}