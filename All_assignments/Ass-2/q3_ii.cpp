// Q) Given an array A of n elements, each of which is an integer in the range [1, n2]. How do we sort the array in O(n) time?

// ALGORITHM:-
// 1.	Take all the array elements as the input.
// 2.	Reduce all the elements of the array by 1
// 3.	Countsort the elements of the array two times and store the result back into the same array.
// 4.	Add 1 to each element of the array.
// 5.	Display the sorted array. 

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void countSort(vector<ll> &v, int n, int exp)
{

    int output[n];
    int i, count[n];
    for (int i = 0; i < n; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[(v[i] / exp) % n]++;

    for (i = 1; i < n; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(v[i] / exp) % n] - 1] = v[i];
        count[(v[i] / exp) % n]--;
    }

    for (i = 0; i < n; i++)
        v[i] = output[i];
}

void sort(vector<ll> &v, int n)
{
    countSort(v, n, 1);
    countSort(v, n, n);
}

void printv(vector<ll> &v, int n)
{
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
}
int main()
{

    vector<ll> v={1,6,4,8,26,15,20,9}; 
    int n = v.size();

    for (ll i = 0; i < n; i++)
    {
        v[i]--;
    }
    sort(v, n);
    for (ll i = 0; i < n; i++)
    {
        v[i]++;
    }
    printv(v, n);
    return 0;
}

TIME AND SPACE COMPLEXITY:-
The time complexity of the above algorithm is O(N) and the space complexity is O(N). 
