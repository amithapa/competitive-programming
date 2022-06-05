/*
Author:      Amit Thapa
Source:      Geek for geeks
Date:        28 May 2022 11:30PM
Link:        https://www.geeksforgeeks.org/check-if-a-given-graph-is-bipartite-using-dfs/?ref=lbp
Title:       Check if a given graph is Bipartite using DFS
*/
#include<iostream>
#include<vector>
using namespace std;

const int N = 10000;

void addEdge(vector<int> g[], int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

bool isBipartite(vector<int> adj[], vector<bool> visited, vector<int> color, int u) {
    for(int v: adj[u]) {
        if(visited[v]) {
            if(color[u] == color[v]) return false;
            continue;
        }
        visited[v] = true;
        color[v] = !color[u];
        if(!isBipartite(adj, visited, color, v)) return false;
    }
    return true;
}

void solve() {
    int n = 6;
    vector<int> adj[n+1];
    vector<bool> visited(n+1);
    vector<int> color(n+1);


    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 1);
    addEdge(adj, 3, 2);

    visited[1] = true;
    color[1] = 0;

    if(isBipartite(adj, visited, color, 1)) {
        cout << "Is Bipartite\n";
    } else {
        cout << "Is not Bipartite\n";
    }


}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}

