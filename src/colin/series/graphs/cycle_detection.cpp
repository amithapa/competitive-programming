#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 10005;

vector<int> adj[N];
vector<int> cycle;
int state[N];
bool found = false;

bool dfs (int u) {
    
    if(state[u] != 0) return;
    state[u] = 1;
    
}

void addEdge(int u, int v) {
    adj[u].push_back(v);
}

void solve() {
    int n = 4;
    int distance[n+1];
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);

    memset(distance, -1, sizeof(distance));
    int start = 2;

    bfs(start, distance);

    for(int i=1; i <= n; i++) {
        cout << distance[i] << " ";
    }
    cout << "\n";

}

int main() {
    solve();

    return 0;
}