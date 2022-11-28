// Q1) Given an array A[0…n-1] of n numbers containing repetition of some number. Given an algorithm for checking whether there are repeated
// element or not. Assume that we are not allowed to use additional space (i.e., we can use a few temporary variable, O(1) storage).
// ANS==>

// Algorithm:-->

// 1.	Traverse the given array from start to end.
// 2.	For every element in the array increment the arr[i]%n‘th element by n.
// 3.	Now traverse the array again and print all those indexes i for which arr[i]/n is greater than 1. Which guarantees that the number n has been added to that index
// 4.	This approach works because all elements are in the range from 0 to n-1 and arr[i] would be greater than n only if a value “i” has appeared more than once.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "enter size of arr:";
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // count the frequency
    int arr_size=arr.size();
    for (int i = 0; i < arr_size; i++)
    {
        arr[arr[i] % arr_size] = arr[arr[i] % arr_size] + arr_size;
    }
    
    int count_repeating_ele=0;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] >= arr_size * 2)
        {
            count_repeating_ele++;
        }
    }
    if(count_repeating_ele>0)
    cout<<"YES,arr have contained some repetition number\n";
    else
    cout<<"No,reqpeated nuber founded\n";
    return 0;
}