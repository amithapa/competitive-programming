#include <iostream>
#include <vector>
#include <climits>
#include<queue>
using namespace std;

const int N = 500005;

int degree[N];
vector<int> adj_list[N];
bool visited[N];



void solve() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,k, u, v;

    cin >> n >> m;

    for(int i=0; i < m; i++) {
        cin >> k;
        int v[k];
        for(int j=0; j < k; j++) {
            cin >> v[j];
        }
        for(int j=0; j < k-1; j++) {
            adj_list[v[j]].push_back(v[j+1]);
            adj_list[v[j+1]].push_back(v[j]);
        }
    }

    for(int i=1; i <= n; i++) {
        if(visited[i]) continue;
        vector<int> component;

        queue<int> q;
        q.push(i);

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            if(visited[u]) continue;
            
            visited[u] = true;
            component.push_back(u);

            for(int y: adj_list[u]) {
                if(visited[y]) continue;
                q.push(y);

            }            
        }
        for(int x: component) {
            degree[x] = component.size();
        }

    }
    for(int i=1; i <= n; i++) {
        cout << degree[i] << " ";
    }
    cout << "\n";


}

int main() {
    solve();
    return 0;
}