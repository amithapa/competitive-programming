#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v) {
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

void print_array(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

struct point {
    int x, y;
    bool operator<(const point &p) {
        if(x == p.x) return y < p.y;
        else return x < p.x;
    };
};

bool comp(string a, string b) {
    if(a.size() == b.size()) return a < b;
    else return a.size() < b.size();
}

int main() {
    vector<int> v = {4,3,8,1,9,2,5,6};

    print_vector(v);
    // sort(v.begin(), v.end());
    sort(v.rbegin(), v.rend());
    print_vector(v);

    int n = 7;
    int a[] = {4,2,5,3,5,8,3};
    
    print_array(a, n);
    sort(a, a+7);
    print_array(a, n);
    string s = "monkey";
    cout << s << "\n";
    sort(s.begin(), s.end());
    cout << s << "\n";

    vector<pair<int, int>> vp;
    vp.push_back({1, 5});
    vp.push_back({2, 3});
    vp.push_back({1, 2});
    for(pair<int, int> p: vp) {
        cout << p.first << " " << p.second << "\n";
    }
    sort(vp.begin(), vp.end());
    cout << "----\n";

    for(pair<int, int> p: vp) {
        cout << p.first << " " << p.second << "\n";
    }
    

    vector<string> vs = {"zaltan", "tanishka", "amit", "sabina", "amir"};
    for(string s: vs) {
        cout << s << " ";
    }
    cout << "\n";

    sort(vs.begin(), vs.end(), comp);
    for(string s: vs) {
        cout << s << " ";
    }
    cout << "\n";
    return 0;
}