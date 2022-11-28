// Q) Let A and B tow arrays of n elements, each. Given a number K, give an O (nlogn) time algorithm for determining whether
//  there exists a ϵ A and b ϵ B such that a+b =K.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    int K;
    cout<<"enter K:";
    cin>>K;

    int flag=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i]+B[j]==K)
            {
                cout<<"Yes,there exit a from A and b from B such that a+b=K\n";
                cout<<"a:"<<A[i]<<"  b:"<<B[j]<<"  K:"<<K<<endl;
                flag=0;
                break;
            }
        }
        if(flag==0)
        break;
    }

    if(flag)
    cout<<"No,there is no --> a from A and b from B such that a+b=K\n";

    
}

Time complecity ->O(n^2)  as we have travverse twicly in for loop
Space complecity is O(1)-->as we have used only constant space only