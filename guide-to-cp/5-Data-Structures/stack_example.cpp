# include <iostream>
# include <stack>
using namespace std;

int main() {
    stack<int> s;

    s.push(2);
    s.push(5);

    cout << s.top() << "\n";

    s.pop();

    cout << s.top() << "\n";

    return 0;
}