#include <bits/stdc++.h>
using namespace std;

// ALGORITHM:-
// 1.Take the array of strings as an input to the array.
// 2 Iterate over each string in the array and sort that string and push it into the unordered map
//   as a key and insert the elements which are anagram of it into the value array of the map.
// 3.After inserting the anagrams sort the array of anagrams. 4 Display the result.

int main()
{
    int n;
    cout<<"Enter the number of words in the array of string:";
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //map<string, vector<string>> umap;  //used red-balck tree-->that uses  self-balancing binary search tree so Tc==best(log(n)) /worst log(n)+balancing for insertion and detion
    unordered_map<string, vector<string>> umap;  //used hashtable so Tc==best(1) /worst O(n) for insertion and deletion and searching
    for (int i = 0; i < n; i++)
    {
        string word = arr[i];
        string letters=word;

        string newword=letters;
        sort(letters.begin(),letters.end());
        umap[letters].push_back(word);
    }

    cout<<"ans:";
    for (auto it = umap.begin(); it != umap.end(); it++)
    {
        sort(umap[it->first].begin(),umap[it->first].end());
        auto values =umap[it->first]; 
        if (values.size() >= 1)
        {
            cout << "[";
            for (int i = 0; i < values.size() - 1; i++)
            {
                cout << values[i] << ",";
            }
            cout << values[values.size() - 1];
            cout << "]";
        }
    }

    return 0;
}

// Complexity Analyse
// The time complexity of the above algorithm is O(n*mlogm) 
// where n is the number of words in the array and m is the maximum number anagrams of a word in the array.