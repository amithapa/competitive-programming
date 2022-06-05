#include<iostream>
#include<vector>
#include<stack>
#include <map>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int> adj[], vector<int> &path, int src, bool visited[]) {
    if(visited[src]) return;
    visited[src] = true;
    path.push_back(src);

    for(int v: adj[src]) {
        if(visited[v]) continue;
        dfs(adj, path, v, visited);    
    }
}

void solve() {
    int n = 4;
    vector<int> adj[5];
    bool visited[5] = {false};
    vector<int> path;
    map<int, char> alphas;

    alphas.insert(pair<int, char>(1, 'A'));
    alphas.insert(pair<int, char>(2, 'B'));
    alphas.insert(pair<int, char>(3, 'C'));
    alphas.insert(pair<int, char>(4, 'D'));

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);


    dfs(adj, path, 2, visited);

    for(int x : path) {
        cout << alphas[x] << " ";
        if(x == 4) break;
    }
    cout << "\n";


}

int main() {
    solve();
    return 0;
}