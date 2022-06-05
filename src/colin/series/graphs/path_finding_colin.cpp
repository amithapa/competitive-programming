#include<iostream>
#include<vector>
#include<stack>
#include <map>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int> adj[], vector<int> &parent, int src, bool visited[], int parent_index) {
    if(visited[src]) return;
    visited[src] = true;
    parent[src] = parent_index;


    for(int v: adj[src]) {
        if(visited[v]) continue;
        dfs(adj, parent, v, visited, src);    
    }
}

void solve() {
    int n = 4;
    vector<int> adj[5];
    bool visited[5] = {false};
    vector<int> parent(5);
    map<int, char> alphas;

    alphas.insert(pair<int, char>(1, 'A'));
    alphas.insert(pair<int, char>(2, 'B'));
    alphas.insert(pair<int, char>(3, 'C'));
    alphas.insert(pair<int, char>(4, 'D'));

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);


    int start = 2;
    int end = 4;

    dfs(adj, parent, 2, visited, -1);

    vector<int> path;
    int tmp = end;

    while(tmp != -1) {
        path.push_back(tmp);
        tmp = parent[tmp];
    }
    reverse(path.begin(), path.end());
    for(int x: path) {
        cout << alphas[x] << " ";
    }

    cout << "\n";


}

int main() {
    solve();
    return 0;
}