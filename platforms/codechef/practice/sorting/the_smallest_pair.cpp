/*
https://www.codechef.com/problems/SMPAIR
You are given a sequence a1, a2, ..., aN. Find the smallest possible value of ai + aj, where 1 ≤ i < j ≤ N.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows. 

The first line of each description consists of a single integer N.

The second line of each description contains N space separated integers - a1, a2, ..., aN respectively.

Output
For each test case, output a single line containing a single integer - the smallest possible sum for the corresponding test case.

Constraints
T = 105, N = 2 : 13 points.
T = 105, 2 ≤ N ≤ 10 : 16 points.
T = 1000, 2 ≤ N ≤ 100 : 31 points.
T = 10, 2 ≤ N ≤ 105 : 40 points.
1 ≤ ai ≤ 106

Sample Input 1 
1
4
5 1 3 4

Sample Output 1 
4
*/

# include<iostream>
# include<algorithm>
#include <climits>
using namespace std;



int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t, n, minimum;
    int arr[100001];
    cin >> t;
    while(t--) {
        minimum = INT_MAX;
        cin >> n;
        for(int i=0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        for(int i=0; i < n-1; i++) {
            minimum = min(minimum, arr[i] + arr[i+1]);
        }
        cout << minimum << "\n";
    }
    return 0;
}