// ALGORITHM:-
// 1.	First we take the pairs of height and weight in array of pairs
// 2.	We sort the above pairs using insort and then compare the adjacent heights and weight if any of the pair violates the rules remove that pair.
// 3.	Display the result.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter n:";
    cin >> n;
    vector<pair<int, int>> vp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            vp[i] = {0, 0};
            continue;
        }
        cin >> vp[i].first;
        cin >> vp[i].second;
    }

    sort(vp.begin(), vp.end());
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vp[i].first < vp[i - 1].first)
        {
            continue;
        }
        if (vp[i].second < vp[i - 1].second)
        {
            continue;
        }
        count++;
        // cout << vp[i].first << " " << vp[i].second << endl;
    }
    cout << "The max length of the tower is " << count << endl;
    return 0;
}

// TIME AND SPACE COMPLEXITY:-
// The time complexity for the above algorithm is O(NlogN) where N is the number of pairs of height and weight.
// The space complexity of the above algorithm is O(1) as there is no extra space used.

