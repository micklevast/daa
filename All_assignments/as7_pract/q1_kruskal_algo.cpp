#include <iostream>
#include <vector>
#include <list>
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
    int findPar(int node, vector<int> &par)
    {
        if (node = par[node])
            return node;

        return par[node] = findPar(par[node], par);
    }
    void union_karo(int n1, int n2)
    {
        int p1 = findPar(n1, parent);
        int p2 = findPar(n2, parent);

        if (p1 > p2)
            parent[p2] = p1;
        else if (p1 < p2)
            parent[p1] = p2;
        else
        {
            parent[p1] = p2;
            rank[p2]++;
        }
    }
};

class MyGraph
{
public:
    void makeGraph(vector<list<pair<int, int>>> &adjList, int node1, int node2, int wgh)
    {
        // cout << "make:\n";
        adjList[node1].push_front({node2, wgh});
        adjList[node2].push_front({node1, wgh});
        // cout << "maked\n";
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
};

int main()
{
    // MyGraph g;
    // int edge;
    // cout << "enter no of edge u wanted:";
    // cin >> edge;
    // vector<list<pair<int, int>>> adj(edge + 1);
    // vector<int> visited(edge + 1); // as node is started from 1 index
    // for (int i = 0; i < edge; i++)
    // {
    //     cout << "enter node and weight:" << i << endl;
    //     int node1, node2, weight;
    //     cin >> node1 >> node2 >> weight;
    //     g.makeGraph(adj, node1, node2, weight);
    // }
    // g.display_graph(adj);

    // disJointSet g(5);
}