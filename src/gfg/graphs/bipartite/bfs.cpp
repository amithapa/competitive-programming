/*
Author:      Amit Thapa
Source:      Geek for geeks
Date:        28 May 2022 11:30PM
Link:        https://www.geeksforgeeks.org/bipartite-graph/?ref=lbp
Title:       Check if a given graph is Bipartite using BFS
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isBipartite(vector<int> adj[], int src, int n) {
    bool visited[n+1];
    int color[n+1];
    memset(color, -1, sizeof(color));
    queue<int> q;

    q.push(src);
    color[src] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v: adj[u]) {
            if(color[v] == -1) {
                color[v] = 1-color[u];
                q.push(v);
                continue;
            } else {
                if(color[v] == color[u]) return false;
            }

        }
        
    }
    
    return true;
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void solve() {
    int n = 7;
    vector<int> adj[n+1];

    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    if(isBipartite(adj, 1, n)) {
        cout << "Is Bipartite\n";
    } else {
        cout << "Is not Bipartite\n";
    }
}

int main() {
    solve();
    return 0;
}