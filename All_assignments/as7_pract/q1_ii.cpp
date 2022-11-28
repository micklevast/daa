#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
class disJointSet
{
public:
    vector<int> parent;
    vector<int> rank;
    disJointSet(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            this->parent.push_back(i);
            this->rank.push_back(1);
        }
    }
    int findPar(int node)
    {
        if (node = parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }
    void union_karo(int n1, int n2)
    {
        int p1 = findPar(n1);
        int p2 = findPar(n2);

        int r1 = rank[p1];
        int r2 = rank[p2];
        // cout << " parent of:" << n1 << ":-" << p1 << "  and of:" << n2 << ":-" << p2 << endl;

        if (r1 > r2)
            parent[p2] = p1;
        else if (r1 < r2)
            parent[p1] = p2;
        else if (r1 == r2)
        {
            parent[p1] = p2;
            rank[p2]++;
            // cout << "rank of :" << p2 << "increaseed.\n";
        }
    }
};

class MyGraph
{
public:
    vector<vector<int>> adjList;
    int ttl_node;
    MyGraph(int ttlNode)
    {
        ttl_node = ttlNode;
    }

    void makeGraph(int wgh, int node1, int node2)
    {
        // cout << "make:\n";
        // adjList[node1].push_front({node2, wgh});
        // adjList[node2].push_front({node1, wgh});
        // cout << "maked\n";
        adjList.push_back({wgh, node1, node2});
    }
    void display_graph(vector<list<pair<int, int>>> adjList)
    {
        int i = 0;
        for (auto lst : adjList)
        {
            cout << "lst " << i++ << ":";
            for (auto lst_val : lst)
            {
                cout << lst_val.first << " " << lst_val.second << "       ";
            }
            cout << endl;
        }
    }

    void kruskalMst()
    {
        sort(adjList.begin(), adjList.end()); // adjlist soet hua
        int ttl_cost = 0;
        disJointSet dset(ttl_node);
        cout << "spanning tree joint are:\n";
        for (int i = 0; i < adjList.size(); i++)
        {
            int weight = adjList[i][0];
            int n1 = adjList[i][1];
            int n2 = adjList[i][2];
            // cout << "wght:" << weight << "  n1:" << n1 << " n2:" << n2 << endl;

            int p1 = dset.findPar(n1);
            int p2 = dset.findPar(n2);
            // cout << "p1:" << p1 << "   p2:" << p2 << endl;
            cout << " parent of:" << n1 << ":-" << p1 << "  and of:" << n2 << ":-" << p2 << endl;

            if (p1 != p2)
            {
                dset.union_karo(p1, p2);
                ttl_cost += weight;
                cout << "joined:" << n1 << "------" << n2 << endl;
            }
        }
        cout << "minimum cost:" << ttl_cost << endl;
    }
};

int main()
{
    int ttl_node;
    cout << "enter ttl edge:";
    cin >> ttl_node;
    MyGraph g(ttl_node);
    for (int i = 0; i < ttl_node; i++)
    {
        cout << "enter weight,n2,n2: for edge:" << i + 1 << "-->";
        int weight, n1, n2;
        cin >> weight >> n1 >> n2;
        g.makeGraph(weight, n1, n2);
    }
    g.kruskalMst();
}