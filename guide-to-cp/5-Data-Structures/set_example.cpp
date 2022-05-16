# include <iostream>
# include <set>
using namespace std;

int main() {
    set<int> s;

    s.insert(3);
    s.insert(2);
    s.insert(5);
    s.insert(5);
    s.insert(5);


    cout << s.count(3) << "\n";
    cout << s.count(4) << "\n";
    // cout << s.count(5) << "\n";

    s.erase(3);
    s.insert(4);

    cout << s.count(3) << "\n";
    cout << s.count(4) << "\n";

    cout << s.size() << "\n";

    for(auto x: s) {
        cout << x << "\n";
    }

    auto it = s.find(5);
    cout << *it << " <- Found\n";

    it = s.find(12);
    if (it == s.end()) {
        cout << "No found\n";
    }


    return 0;
}