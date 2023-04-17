#include <bits/stdc++.h>

using namespace std;

/*
 * Fibonacci army
 * https://codeforces.com/gym/438582/problem/B
 * Time - O(n)
 * Space - O(n)
 */

int fibonacci(int n)
{
    if (n <= 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    cout << fibonacci(n) << "\n";

    return 0;
}
