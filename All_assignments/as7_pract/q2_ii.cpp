
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
// undirected grph
//
void making_graph(vector<list<pair<int, int>>> &adj, int n1, int n2, int w)
{
    adj[n1].push_front({n2, w});
    adj[n2].push_front({n1, w});
}

void display_adj_list(vector<list<pair<int, int>>> &adj)
{
    for (int i = 1; i < adj.size(); i++)
    {
        cout << i << ":";
        for (auto it : adj[i])
            cout << "(" << it.first << "," << it.second << ") ";
        cout << endl;
    }
}

void min_spanning_tree(vector<list<pair<int, int>>> adj, vector<int> &key, vector<bool> &MST, vector<int> &parent, int source, int N)
{ //--> O(N^2)
    // key[source]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    // MST[source]=true;

    // try for other than source element node-->i.e for others (N-1) node

    for (int i = 0; i < N - 1; i++)
    {
        // try to find out minimum-weighted node from key which are not MST
        // int mini_wgt=INT_MAX;
        int mini_node = pq.top().second;
        pq.pop();
        // for(int j=1;j<N;j++)
        // {
        //     if(!MST[j] && mini_wgt>key[j])
        //     mini_wgt=key[j],mini_node=j;
        // }

        cout << "mini:" << mini_node << endl;

        MST[mini_node] = true;
        for (auto it : adj[mini_node])
        {
            int wgt = it.second;
            int node = it.first;
            if (!MST[node] && wgt < key[node])
            {
                cout << node << " ";
                parent[node] = mini_node;
                pq.push({key[node], node});
                key[node] = wgt;
            }
        }
        cout << endl;
    }

    for (int i = 1; i <= N; i++)
    {
        cout << parent[i] << " -> " << i << endl;
    }
}

int main()
{
    int node = 5;
    vector<list<pair<int, int>>> adj(node + 1);
    vector<int> visited(node + 1, 0);

    int n1, n2, wgt;
    while (true)
    {
        cin >> n1 >> n2 >> wgt;
        if (n1 < 0 || n2 < 0 || wgt < 0)
            break; // breaking condition of loop //as seems -ve node does not exit
        making_graph(adj, n1, n2, wgt);
    }
    vector<int> key(node + 1);    // will contain weight of that indexed node
    vector<bool> MST(node + 1);   // check weather it's included in MST or not
    vector<int> parent(node + 1); // will stored who will the parent in MST of that indexed node
    for (int i = 1; i <= node; i++)
        key[i] = INT_MAX, MST[i] = false, parent[i] = -1;

    // brute-force method
    int source = 1;
    min_spanning_tree(adj, key, MST, parent, source, node);
}