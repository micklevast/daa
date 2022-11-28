#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    cin>>str;
    // cout<<int('a')<<endl<<int('z')<<endl;
    // cout<<int('A')<<endl;
    // cout<<char(65+32)<<endl;
    // cout<<char(int('B')+32)<<endl;
    // cout<<int('Z');
    int small=0,big=0;
    for(int i=0;i<str.length();i++)
    {
        if(int(str[i])<=90)
        big++;
        else
        small++;
    }
    if(big<=small)
    {
       for(int i=0;i<str.length();i++)
       {
            if(int(str[i])<=90)
            {
                str[i]=char(int(str[i])+32);
            }
       }  
    }
    else
    {
       for(int i=0;i<str.length();i++)
       {
            if(int(str[i])>90)
            {
                str[i]=char(int(str[i])-32);
            }
       } 
    }
    cout<<str<<endl;
    // cout<<"ans:"<<int(char('b')-32)<<endl;

}