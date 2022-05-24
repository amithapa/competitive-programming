/*
Connected Components
https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
*/
# include <iostream>
# include <vector>
using namespace std;
const int N = 100005;
vector<int> adj_list[N];
bool visited[N];

void dfs(int current) {
    visited[current] = true;
    for(int next_vertex: adj_list[current]) {
        if(visited[next_vertex]) {
            continue;
        }
        dfs(next_vertex);
    }
}



int main() {
    int n, e, u, v, ans=0;
    cin >> v >> e;
    for(int i=0; i < e; i++) {
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for(int i=1; i <= n; i++) {
        if(visited[i]) {
            continue;
        }
        ans++;
        dfs(i);
    }
    cout << ans << "\n";

    return 0;
}