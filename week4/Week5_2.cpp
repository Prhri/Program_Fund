#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    m=n*n;
    for(int i=1;i<=m;i++)
    {
        cout<<"*";
        if(i%n==0)
            cout<<endl;
    }
}