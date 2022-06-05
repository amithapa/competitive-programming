/*
Author:      Amit Thapa
Source:      Colin Youtube Graphs Steam
Date:        28 May 2022 2:18PM
Link:        https://codeforces.com/gym/317667/problem/D
Title:       Check if a given graph is Bipartite using DFS
Additional:  From youtube Colin steam https://www.youtube.com/watch?v=2hBjTs3qRg0&t=3491s
*/

#include<iostream>
#include<vector>
using namespace std;
const int N = 100005;
vector<int> adj[N];
bool visited[N];
bool color[N];
bool possible = true;

void dfs(int u, bool c) {
    if(visited[u]) return;

    visited[u] = true;
    color[u] = c;

    for(int v: adj[u]) {
        if(!visited[v]) {
            dfs(v, c ^ 1);
        } else {
            if(c == color[v]){
                possible = false;
            } 
        }
    }

}

 void solve() {
    // Solution goes here
    int n, m, u, v;
    cin >> n >> m;

    for(int i=0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i <= n; i++) {
       if(!visited[i]) {
           dfs(i, 0);
       }
    }

    if(possible) {
        int cnt[2] = {0};
        for(int i=1; i <=n; i++) {
            cnt[color[i]]++;
        }
        cout << cnt[0] << "\n";
        for(int i=1; i <=n; i++) {
            if(color[i] == 0) {
                cout << i << " ";
            }
        }
        cout << "\n";
        cout << cnt[1] << "\n";
        for(int i=1; i <=n; i++) {
            if(color[i] == 1) {
                cout << i << " ";
            }
        }
        cout << "\n";

    } else {
        cout << "-1\n";
    }


}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    solve();

    return 0;
}