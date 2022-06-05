#include<iostream>
#include<vector>
#include<stack>
#include <map>
using namespace std;

const int N = 1005;
vector<int> adj[N];
bool visited[N] = {false};
map<int, char> alphas;



void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int u) {
    if(visited[u]) return;
    visited[u] = true;
    cout << alphas[u] << " ";
    for(int v: adj[u]) {
        dfs(v);
    }
}


void solve() {
    int n = 10;

    alphas.insert(pair<int, char>(1, 'A'));
    alphas.insert(pair<int, char>(2, 'B'));
    alphas.insert(pair<int, char>(3, 'C'));
    alphas.insert(pair<int, char>(4, 'D'));
    alphas.insert(pair<int, char>(5, 'E'));
    alphas.insert(pair<int, char>(6, 'F'));
    alphas.insert(pair<int, char>(7, 'G'));
    alphas.insert(pair<int, char>(8, 'H'));
    alphas.insert(pair<int, char>(9, 'I'));
    alphas.insert(pair<int, char>(10, 'J'));

    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 3);


    addEdge(adj, 8, 9);
    addEdge(adj, 6, 9);

    addEdge(adj, 2, 7);

    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        dfs(i);
        cout << "\n";
    }



}

int main() {
    solve();
    return 0;
}