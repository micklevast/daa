// ALGORITHM:-
// 1.	Take the all elements as the input in the array.
// 2.	Sort all the elements in the array.
// 3.	Take input the element x whose Rank we need to calculate.
// 4.	Count the number of elements which are less than or equal to x.
#include <bits/stdc++.h>
using namespace std;
int getRankOfNumber(vector<int> &v, int x)
{
    int count = 0;
    int i = 0;
    while (true)
    {
        if (v[i] <= x && v[i + 1] <= x)
        {
            count++;
        }
        else
        {
            break;
        }
        i++;
    }
    return count;
}

int main()
{
    int N;
    cout<<"enter N:";
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    cout<<"enter which rank u wanted:";
    int getRank;
    cin >> getRank;

    // cout<<"The rank of "<<getRank<<" is "<<getRankOfNumber(v,getRank)<<endl;
    cout << getRankOfNumber(v, getRank) << endl;

    return 0;
}
// TIME AND SPACE COMPLEXITY:-
// The time complexity of the above algorithm is O(NlogN)
// the space complexity is O(1) as there is no extra space used.

