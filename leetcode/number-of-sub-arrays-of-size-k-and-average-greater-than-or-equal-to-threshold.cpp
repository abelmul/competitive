#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int size = arr.size();
        double average = 0;
        int window_sum = 0;
        int count = 0;
        
        if(size < k)
            return 0;
        
        for(int i = 0; i < k; ++i)
            window_sum += arr[i];
        
        if ((double)window_sum/k >= threshold)
            ++count;
        
        for(int i = k; i < size; ++i) {
            window_sum += arr[i] - arr[i-k];
            if ((double)window_sum/k >= threshold)
                ++count;
        }
        
        return count;
    }
};
