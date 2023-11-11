#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int strStr(string haystack, string needle)
    {
        int size = haystack.size(), needleSize = needle.size();

        for (int i = 0; i <= size - needleSize; ++i) {
            int k = i;
            int j = 0;
            for (j = 0; j < needleSize && haystack[k] == needle[j]; ++j, ++k)
                ;

            if (j == needleSize) {
                return i;
            }
        }

        return -1;
    }
};
