#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define pii pair<int, int>

// adjency list
vector<pii> adj[N];
// distance array
int dis[N];
//  nodes and edges
int n, m;

// Dijkistra's algorithm for shortest path
void bfs(int src)
{
    // min heap
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    // distance from source  to itself
    dis[src] = 0;

    while (!pq.empty())
    {
        pii temp = pq.top();
        pq.pop();
        int node = temp.second;
        int wt = temp.first;

        // traversing each neighbour of node temp
        for (auto child : adj[node])
        {
            int nChild = child.first;
            int nwt = child.second;

            // relaxing nodes

            if (dis[nChild] > (nwt + dis[node]))
            {
                dis[nChild] = nwt + dis[node];
                pq.push({dis[nChild], nChild});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << "A"
             << "  to " << char(i + 64) << "  ->  " << dis[i] << "\n";
}

signed main()
{
    cout << "Enter the number of nodes and the number of edges: ";

    cin >> n >> m;

    for (int i = 0; i < N; i++)
    {
        adj[i].clear();
        dis[i] = INT_MAX;
    }
    cout << "Edges " << endl;
    // storing graph
    for (int i = 1; i <= m; i++)
    {
        char a, b;
        cin >> a >> b;
        int u = a - 64, v = b - 64, wt;
        cin >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    bfs(1);
}
