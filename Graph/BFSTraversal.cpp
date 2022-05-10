// Disconnected Graphs & Connected Components of Graph

/*
    for(i=1->n)
    {
        if(vis[i] == 0)
        {
            bfs(i);
        }
    }

    BFS- Traversing the adjacent nodes

    TC- O(N+E)= O(N)
    SC- O(N+E) + O(N) + O(N) = O(N)
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfsGraph(int V, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(V+1, 0);

    for(int i=1; i<=V; i++)
    {
        if(!vis[i])
        {

        }
    }
}