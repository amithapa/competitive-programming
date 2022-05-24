// https://codeforces.com/gym/317667/problem/A
# include <iostream>
# include <vector>
using namespace std;
const int N = 30005;
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
    int n, t, a;

    cin >> n >> t;

    for(int i=1; i < n; i++) {
        cin >> a;
        adj_list[i].push_back(i+a);
    }
    dfs(1);
    if(visited[t]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}