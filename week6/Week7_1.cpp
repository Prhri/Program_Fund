#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    n=(n*2)-1;
    for(int i=0;i<n*2;i+=2)
    {
        for(int j=n/2;j>abs(n-1-i)/2;j--)
            cout<<" ";
        for(int j=0;j<=abs(n-1-i);j++)
            cout<<"*";
        cout<<endl;
    }
}