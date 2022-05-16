# include <iostream>
# include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);

    cout << v[0] << "\n";
    cout << v[1] << "\n";
    cout << v[2] << "\n";    

    // Initial values
    vector<int> a(8);
    vector<int> b(8, 2);
    for(int i=0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for(auto x: b) {
        cout << x << " ";
    }
    cout << "\n";

    cout << v.back() << "\n";

    vector<int> k = {2,3,3,5,7,8,8,8};
    auto l = lower_bound(k.begin(), k.end(), 5);
    auto m = upper_bound(k.begin(), k.end(), 5);

    cout << *l << " " << *m << "\n";

    return 0;
}