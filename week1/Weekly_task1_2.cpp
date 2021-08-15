#include<iostream>
using namespace std;
int main()
{
    double a[2];
    cin>>a[0]>>a[1];
    cout<<a[0]+a[1]<<endl;
    cout<<a[0]-a[1]<<endl;
    cout<<a[0]*a[1]<<endl;
    if(a[1]==0)
        cout<<"Can't divide by 0";
    else
        cout<<a[0]/a[1]<<endl;
}