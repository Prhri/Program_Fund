#include<iostream>
using namespace std;
int main()
{
    double a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    cout<<a*b<<endl;
    if(b==0)
        cout<<"Can't divide by 0";
    else
        cout<<a/b<<endl;
}