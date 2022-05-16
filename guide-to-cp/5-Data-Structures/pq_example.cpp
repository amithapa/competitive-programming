# include <iostream>
# include <queue>

using namespace std;

int main() {
    // priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pq;

    pq.push(3);
    pq.push(5);
    pq.push(7);
    pq.push(2);

    cout << pq.top() << "\n";
    pq.pop();
    cout << pq.top() << "\n";
    pq.pop();
    pq.push(6);
    cout << pq.top() << "\n";
    pq.pop();

    return 0;
}