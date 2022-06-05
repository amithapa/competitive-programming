# include <iostream>
# include <vector>
#include <climits>
using namespace std;

const int N = 100005;
bool visited[N];
vector<int> adj_list[N];
long long coins[N];


long long get_minimum_coin(int frnd) {
    visited[frnd] = true;
    long long minimum_gold = coins[frnd];

    for(int adjacent_friend : adj_list[frnd]) {
        if(visited[adjacent_friend]) {
            continue;
        }
        minimum_gold = min(minimum_gold, get_minimum_coin(adjacent_friend));
    }
    return minimum_gold;
}

int main() {
    int n, m, u, v;
    long long total_gold=0;

    cin >> n >> m;
    for(int i=1; i <= n; i++) {
        cin >> coins[i];
    }
    for(int i=0; i < m; i++) {
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for(int i=1; i <= n; i++) {
        if(visited[i]) {
            continue;
        }
        total_gold += get_minimum_coin(i);
    }

    cout << total_gold << "\n";



    return 0;
}