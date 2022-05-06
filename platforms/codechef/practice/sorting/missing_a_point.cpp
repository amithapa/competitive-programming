/*
https://www.codechef.com/problems/PTMSSNG
Missing a Point

Chef has N axis-parallel rectangles in a 2D Cartesian coordinate system. 
These rectangles may intersect, but it is guaranteed that all their 4N vertices are pairwise distinct.

Unfortunately, Chef lost one vertex, and up until now, none of his fixes have worked 
(although putting an image of a point on a milk carton might not have been the greatest idea after all…). 
Therefore, he gave you the task of finding it! 
You are given the remaining 4N−1 points and you should find the missing one.

Input
The first line of the input contains a single integer T denoting the number of test cases. 
The description of T test cases follows.
The first line of each test case contains a single integer N.
Then, 4N−1 lines follow. Each of these lines contains two space-separated integers x and y denoting a vertex (x,y) of some rectangle.

Output
For each test case, print a single line containing two space-separated integers X and Y ― the coordinates of the missing point. 
It can be proved that the missing point can be determined uniquely.

Constraints
T≤100
1≤N≤2⋅105
|x|,|y|≤109
the sum of N over all test cases does not exceed  2⋅105
*/

# include<iostream>
# include<algorithm>
# include<vector>
#include <climits>
using namespace std;

bool sort_by_second(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t, n, x, y, missing_x, missing_y;

    cin >> t;
    while(t--) {

        vector<pair<int, int>> points;
        cin >> n;
        for (int i=0; i < (4*n - 1); i++) {
            cin >> x >> y;
            points.push_back(make_pair(x,y));
        }

        missing_x = points[0].first;
        missing_y = points[0].second;
        
        for (int i=1; i < points.size(); i++) {
            pair<int, int> point = points[i];
            missing_x ^= point.first;
            missing_y ^= point.second;
        }

        cout << missing_x << " " << missing_y << "\n";
    }
    return 0;
}

/*
1
2
1 1
1 2
2 1
2 2
4 3
9 3
4 6

9 6
1
1

-1 -21
0 2
 1


*/