#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int> adj[], int src, int distance[], bool visited[]) {
    if(visited[src]) return;
    visited[src] = true;

    for(int v: adj[src]) {
        if(visited[v]) continue;
        distance[v] = distance[src] + 1;
        dfs(adj, v, distance, visited);    
    }
}

void solve() {
    vector<int> adj[9];
    int distance[9] = {0};
    bool visited[9] = {false};

    addEdge(adj, 1, 3);
    addEdge(adj, 1, 6);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 2);
    addEdge(adj, 4, 6);
    addEdge(adj, 3, 8);
    addEdge(adj, 8, 7);
    addEdge(adj, 8, 5);
    addEdge(adj, 5, 7);

    distance[0] = 1;
    dfs(adj, 1, distance, visited);

    for(int i=1; i <= 8; i++) {
        cout << distance[i] << " ";
    }
    cout << "\n";


}

int main() {
    solve();
    return 0;
}