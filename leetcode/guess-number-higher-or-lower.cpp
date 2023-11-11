#include <bits/stdc++.h>

using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */
int guess(int num);

class Solution
{
 public:
    int guessNumber(int n)
    {
        int start = 1;
        int end = n;

        int m, g;

        while (start <= end) {
            m = start + (end - start) / 2;
            g = guess(m);

            cout << m << " " << g << "\n";

            if (g == 0) {
                return m;
            } else if (g == 1) {
                start = m + 1;
            } else {
                end = m - 1;
            }
        }

        return start;
    }
};
