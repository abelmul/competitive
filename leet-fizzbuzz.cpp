#include <vector>
#include <string>

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> a;
        for(int i = 1; i < n+1; ++i) {
            if (i % 15 == 0) {
                a.push_back("FizzBuzz");
            } else if (i % 5 == 0) {
                a.push_back("Buzz");
            } else if (i % 3 == 0) {
                a.push_back("Fizz");
            } else {
                a.push_back(std::to_string(i));
            }
        }
        return a;
    }
};
