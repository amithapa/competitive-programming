#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 10005;

vector<int> adj[N];
bool visited[N];


void bfs(int src, int distance[]) {
    queue<int> q;
    q.push(src);
    distance[src] = 0;
    visited[src] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v: adj[u]) {
            if(visited[v]) continue;
            distance[v] = distance[u] + 1;
            visited[v] = true;
            q.push(v);
        }
    }
}

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
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


    // for(int i=1; i <= n; i++) {
    //     cout << i << " -> ";
    //     for(int v: adj[i]) {
    //         cout << v << " ";
    //     }
    //     cout << "\n";
    // }

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