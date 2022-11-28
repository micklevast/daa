#include <bits/stdc++.h>
using namespace std;

// ALGORITHM:-
// The code is doing the following:
// 1.	It is creating a hashmap with key as the string and value as vector of indices where that string occurs.
// 2.	It is taking input from user for the string to be searched.
// 3.	It is searching the string in the hashmap.
// 4.	If the string is found, it prints the first index where it occurs.
// 5.	If the string is not found, it prints -1.
// The key is the string and the value is a vector of indices where that string occurs. We can then use the find() function to check
// if the string exists in the map or not. If it does, we can print the first index of the vector.


int main()
{
    int N=8;

    string arr[N] = {"at", "", "", "ball", "", "", "car", ""};
    unordered_map<string, vector<int>> umap;
    for (int i = 0; i < N; i++)
    {
        umap[arr[i]].push_back(i);
    }
    string find;
    cout<<"enter string whose index want to know:";
    cin >> find;

    cout<<"index:";
    cout << umap[find][0] << endl;

    return 0;
}


// Complexity analyse
// 1>The time complexity of the above algorithm is O(N) where N is the number of string words in the array.
// 2>The space complexity of the above algorithm is O(N) as we are using hashmap to store the values