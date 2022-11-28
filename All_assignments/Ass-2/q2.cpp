// Q)	Given an array A[0…n-1] , where each element of the array represents a vote in the election. Assume that each vote is given as an
// integer representing the ID of the chosen candidate. Given an algorithm for determining who wins the election.

// ALGORITHM-->
// 1.	take input array of vote
// 2.	find each frequency using map
// 3.	find max frequency from map
// 4.   print max frequency condidate
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "enter size of arr:";
    cin >> n;
    vector<int> arr(n);
    map<int, int> count_vote;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        count_vote[arr[i]]++;
    }

    map<int, int>::iterator it;
    it = count_vote.begin();
    int max_vote = it->second;
    int winner_condidate = it->first;

    for (auto val : count_vote)
    {
        // cout<<<<"->"<<val.second<<endl;
        // break;
        if (max_vote < val.second)
        {
            max_vote = val.second;
            winner_condidate = val.first;
        }
    }
    cout << "winner is ocndidate:" << winner_condidate << endl;
}
