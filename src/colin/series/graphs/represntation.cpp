#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void solve() {
    vector<int> adj[5];

    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);

    for(int i=1; i <= 4; i++) {
        cout << i << " -> ";
        for(int v: adj[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }


}

int main() {
    solve();
    return 0;
}