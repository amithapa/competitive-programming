# include <iostream>
# include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(2);
    q.push(5);

    cout << q.front() << "\n";

    q.pop();

    cout << q.back() << "\n";

    return 0;
}