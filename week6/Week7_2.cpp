#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m=n;
    n=(n*2)-1;
    int I;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            //cout<<m-abs(m-1-i)-1<<j<<" ";
            if(m-abs(m-1-i)-1<=j && m-abs(m-1-i)-1+j<n)
                cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
        
}