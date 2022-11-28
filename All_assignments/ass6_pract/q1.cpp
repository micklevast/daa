#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int My_greater(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first > p2.first;
}
int main()
{
    vector<pair<int, int>> jobP_jobD;
    // jobP_jobD.push_back({100, 2});
    jobP_jobD.push_back({3, 1});
    jobP_jobD.push_back({5, 3});
    jobP_jobD.push_back({20, 4});
    jobP_jobD.push_back({18, 3});
    jobP_jobD.push_back({1, 2});
    jobP_jobD.push_back({6, 1});
    jobP_jobD.push_back({30, 2});
    // jobP_jobD.push_back({20, 4});
    // jobP_jobD.push_back({10, 1});
    // sort(jobP_jobD.begin(), jobP_jobD.end(), greater<pair<int, int>>());
    sort(jobP_jobD.begin(), jobP_jobD.end(), My_greater);
    vector<int> deadL(11, -1);
    int maxP = 0;
    for (int i = 0; i < jobP_jobD.size(); i++)
    {
        // cout << jobP_jobD[i].first << " " << jobP_jobD[i].second << endl;

        for (int j = jobP_jobD[i].second; j >= 1; j--)
        {
            if (deadL[j] == -1)
            {
                deadL[j] = i + 1; // i+1 th job has been fixed here
                cout << "for jobP:" << jobP_jobD[i].first << " pos:" << j << " is selected\n";
                maxP += jobP_jobD[i].first;
                break;
            }
        }
    }
    cout << "ans:";
    cout << maxP << endl;
}