// Q1) You are given two sorted array, A and B,
// where A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order.

// ALgorithm
// 1.take input array A,B of size(n+m) and m
// 2.traverse array A and B simaltaneously
//         i.if(A[i]<=b[j]) then increase i to i+1
//         ii.else swap A and B element then Sort B so that at B[j=0],it should have smallest nummber among B array
// 3.merge B to A
// 4.print A

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void display_arr(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
}
int main()
{
    int n, m;
    cout<<"Enter the size of A and B:"<<endl;
    cin >> n >> m;

    vector<int> A(n + m, 0),B(m);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>B[i];
    }

// -->as given is that array is alrealy sorted-->so no use of sorting again
    // sort(A.begin(),A.end());
    // sort(B.begin(),B.end());
    // display_arr(A);cout<<endl;

    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(A[i]<=B[j])
        {
            i++;
        }
        else
        {
            swap(A[i],B[j]);
            sort(B.begin(),B.end());
        }
    }
    for(int i=n;i<n+m;i++)
    A[i]=B[i-n];

    cout<<"A merged with B array:";
    display_arr(A);
}

// time complexity-->O(n)*nlog(m) traversing and for sorting at worst case-->overall O(n)*nlog(m) 
// space complexity-->O(1) as used constant  space only