#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    ans=n/5;
    if(n%5)
    ans++;
    cout<<ans<<endl;
}