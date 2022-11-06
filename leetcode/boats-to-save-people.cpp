#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boat_count = 0;
        
        sort(people.begin(), people.end());
        
        auto iterator = people.begin();
        
        while(iterator != people.end()) {
            auto scan_iterator = --people.end();
            while (scan_iterator != iterator) {
                if (*iterator + *scan_iterator <= limit) {
                    people.erase(scan_iterator);
                    break;
                }
                --scan_iterator;
            }
            
            ++boat_count;
            ++iterator;
        }
        
        return boat_count;
    }
};
