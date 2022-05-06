/*
https://www.codechef.com/problems/MAXDIFF
Chef has gone shopping with his 5-year old son. They have bought N items so far. The items are numbered from 1 to N, and the item i weighs Wi grams.

Chef's son insists on helping his father in carrying the items. He wants his dad to give him a few items. 
Chef does not want to burden his son. But he won't stop bothering him unless he is given a few items to carry. 
So Chef decides to give him some items. Obviously, Chef wants to give the kid less weight to carry.

However, his son is a smart kid. To avoid being given the bare minimum weight to carry, he suggests that the items are split into two groups, 
and one group contains exactly K items. Then Chef will carry the heavier group, and his son will carry the other group.

Help the Chef in deciding which items should the son take. Your task will be simple. 
Tell the Chef the maximum possible difference between the weight carried by him and the weight carried by the kid.
Input:
The first line of input contains an integer T, denoting the number of test cases. 
Then T test cases follow. 
The first line of each test contains two space-separated integers N and K. 
The next line contains N space-separated integers W1, W2, ..., WN.

Output:
For each test case, output the maximum possible difference between the weights carried by both in grams

Constraints:
1 ≤ T ≤ 100
1 ≤ K < N ≤ 100
1 ≤ Wi ≤ 100000 (105)

Sample Input 1 
2
5 2
8 4 5 2 10
8 3
1 1 1 1 1 1 1 1

Sample Output 1 
17
2
*/

# include<iostream>
# include<algorithm>
#include <climits>
using namespace std;



int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long t, n, k, first_k_weights, total, last_k_weights;
    long long w[100001];
    cin >> t;
    while(t--) {
        total = first_k_weights = last_k_weights = 0;
        cin >> n >> k;
        for(long long i=0; i < n; i++)
            cin >> w[i];
        sort(w, w+n);
        for(long long i=0; i < n; i++) {
            if (i < k) {
                first_k_weights += w[i];
            } 
            if(i >= (n - k)) {
                last_k_weights += w[i];
            }
            total += w[i];

        }
        cout << max(abs((total-first_k_weights) - first_k_weights), abs((total-last_k_weights) - last_k_weights)) << "\n";

    }
    return 0;
}
