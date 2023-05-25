#include <bits/stdc++.h>

using namespace std;

/**
 * Two Buttons
 * https://codeforces.com/gym/445382/problem/A
 *
 * Time - O(m)
 * Space - O(m)
 */

long long solve(long long n, long long m)
{
    long long res;

    deque<long long> queue;
    long long current;
    unordered_map<long long, long long> prev;

    queue.push_back(n);
    prev[n] = 0;

    while (!queue.empty()) {
        current = queue.front();
        queue.pop_front();

        if (current == m) {
            res = prev[m];
            break;
        }

        long long two_times = current << 1;

        if (two_times > 0 && two_times < m << 1 && prev.find(two_times) == prev.end()) {
            queue.push_back(two_times);
            prev[two_times] = prev[current] + 1;
        }

        if (current - 1 > 0 && prev.find(current - 1) == prev.end()) {
            queue.push_back(current - 1);
            prev[current - 1] = prev[current] + 1;
        }
    }

    return res;
}

int main()
{
    int n, m;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    cout << solve(n, m) << "\n";

    return 0;
}
