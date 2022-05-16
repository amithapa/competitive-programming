/*
https://www.codechef.com/problems/TACHSTCK
Chopsticks

[Chopsticks (singular: chopstick) are short, frequently tapered sticks used in pairs of equal 
length, which are used as the traditional eating utensils of China, Japan, Korea and Vietnam. 
Originated in ancient China, they can also be found in some areas of Tibet and Nepal that are 
close to Han Chinese populations, as well as areas of Thailand, Laos and Burma which have 
significant Chinese populations. Chopsticks are most commonly made of wood, bamboo or plastic, 
but in China, most are made out of bamboo. Chopsticks are held in the dominant hand, between 
the thumb and fingers, and used to pick up pieces of food.]

Actually, the two sticks in a pair of chopsticks need not be of the same length. 
A pair of sticks can be used to eat as long as the difference in their length is at most D. 
The Chef has N sticks in which the ith stick is L[i] units long. 
A stick can't be part of more than one pair of chopsticks. 
Help the Chef in pairing up the sticks to form the maximum number of usable pairs of chopsticks.

Input
The first line contains two space-separated integers N and D. The next N lines contain one integer each, the ith line giving the value of L[i].

Output
Output a single line containing the maximum number of pairs of chopsticks the Chef can form

Constraints
1 ≤ N ≤ 100,000 (10 5 )
0 ≤ D ≤ 1,000,000,000 (10 9 )
1 ≤ L[i] ≤ 1,000,000,000 (10 9 ) for all integers i from 1 to N

Sample Input 1 
5 2
1
3
3
9
4

Sample Output 1 
2

Explanation
The 5 sticks have lengths 1, 3, 3, 9 and 4 respectively. 
The maximum allowed difference in the lengths of two sticks forming a pair is at most 2. 
It is clear that the 4th stick (length 9) cannot be used with any other stick. 
The remaining 4 sticks can can be paired as (1st and 3rd) and (2nd and 5th) to form 2 pairs of usable chopsticks.
*/

# include<iostream>
# include<algorithm>
# include<vector>
#include <climits>
using namespace std;

void solve_2() {
    int n, no_of_taps, current_position, last_position, index;
    cin >> n;
    int w[n+1], l[n+1];
    vector<pair<int, int>> weights_with_position(n);
    
    for(int i =0; i < n; i++)
        cin >> w[i];

    for(int i =0; i < n; i++)
        cin >> l[i];

    for(int i=0; i < n; i++)
        weights_with_position[i] = {w[i], i};
    
    sort(weights_with_position.begin(), weights_with_position.end());

    last_position = weights_with_position[0].second;
    no_of_taps = 0;

    for(int i=1; i < n; i++) {
        current_position = weights_with_position[i].second;
        index = weights_with_position[i].second;
        
        while (current_position <= last_position ) {
            current_position += l[index];
            no_of_taps++;
        }
        last_position = current_position;
    }
    cout << no_of_taps << "\n";
}

void solve() {
    int n, no_of_taps, current_position, last_position, index, diff;
    cin >> n;
    int w[n+1], l[n+1];
    vector<pair<int, int>> weights_with_position(n);
    
    for(int i =0; i < n; i++)
        cin >> w[i];

    for(int i =0; i < n; i++)
        cin >> l[i];

    for(int i=0; i < n; i++)
        weights_with_position[i] = {w[i], i};
    
    sort(weights_with_position.begin(), weights_with_position.end());

    last_position = weights_with_position[0].second;
    no_of_taps = 0;

    for(int i=1; i < n; i++) {
        current_position = weights_with_position[i].second;
        index = weights_with_position[i].second;
        
        diff = (current_position <= last_position ) ? ((last_position - current_position + l[index]) / l[index]): 0;
        no_of_taps += diff;
        last_position = current_position + diff * l[index];
    }
    cout << no_of_taps << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}