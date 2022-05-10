/*
    Input- n (no of nodes) & m (no of edges)
            u1,v1
            u2,v2
            ..,..
            um,vm

    Adjacency Matrix- (n+1)*(n+1) - fill the matrix with zeroes

    adj[u][v]=1;
    adj[v][u]=1;
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    int adj[n+1][n+1];

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}

// Adjacency Matrix is used only for small values of N  SC-O(N*N)

/* 
    Adjacency List is used for large values of N
    vector<int>adj[6]- array of int vector

    Space Complexity- O(2*E) where E is the no of edges

    adj[u].push_back(v)
    adj[v].push_back(u)

    * If directed graph
    adj[u].push_back(v)

    For edge weights-
    vector<int,int>adj[6]
    int (node), int (weight)
    adj[u].push_back({v,w})
*/

// For Undirected Graph
int main(){
    int n, m;
    cin>>n>>m;

    vector<int>adj[n+1];
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}

// For Directed Graph
int main(){
    int n, m;
    cin>>n>>m;

    vector<int>adj[n+1];
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    return 0;
}

// For Undirected Graph with weight
int main(){
    int n, m;
    cin>>n>>m;

    vector<pair<int, int>> adj[n+1];
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    return 0;
}