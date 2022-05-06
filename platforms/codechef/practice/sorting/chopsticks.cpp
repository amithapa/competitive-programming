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
*/

# include<iostream>
# include<algorithm>
# include<vector>
#include <climits>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, d, t;
    cin >> n >> d;
    int lengths[n+1], local_diff, count=0;
    for (int i=0; i < n; i++) {
        cin >> lengths[i];
    }
    sort(lengths, lengths+n);

    for(int i=0; i < n-1;) {
        local_diff = lengths[i+1] - lengths[i];
        if(local_diff <= d) {
            count += 1;
            i+= 2;
        } else {
            i += 1;
        }
            
    }
    cout << count << "\n";
    return 0;
}