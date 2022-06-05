#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 10005;

vector<int> adj[N];

void addEdge(int u, int v) {
    adj[u].push_back(v);
}

bool isAllVisited(bool visited[], int n) {
    for(int i=0; i < n; i++) {
        if(!visited[i]) return false;
    }

    return true;
}

void dfs(int u, bool visited[]) {
    visited[u] = true;
    for(int v: adj[u]) {
        if(visited[v]) continue;
        dfs(v, visited);
    }
}

void solve() {
    int n = 8;
    addEdge(0, 1);
    addEdge(0, 2);

    addEdge(1, 3);
    addEdge(4, 1);

    addEdge(5, 2);
    addEdge(5, 6);

    addEdge(6, 4);

    addEdge(6, 0);

    bool visited[N] = {};
    bool found = false;

    for(int i=0; i < n; i++) {
        dfs(i, visited);
        if(isAllVisited(visited, n)) {
            found = true;
            cout << i << "\n";
            break;
        }
        memset(visited, false, sizeof(visited));
    }
    if(!found) {
        cout << "No mother vertex\n";
    }
}

int main() {
    solve();

    return 0;
}