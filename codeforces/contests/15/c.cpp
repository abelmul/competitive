#include <bits/stdc++.h>

/**
 * Company Party
 * https://codeforces.com/gym/436386/problem/C
 * time = O(n)
 * space = O(1)
 */

using namespace std;

int findDepth(unordered_map<int, int>& depths, int key)
{
    if (depths.find(key) != depths.end())
        return depths[key];

    return -1;
}

int main()
{
    int n, res = 1;
    vector<int> a;
    unordered_map<int, int> depths;

    cin >> n;
    a.resize(n);

    for (auto i = 0; i < n; ++i) cin >> a[i];

    // we can return max depth of tree

    for (int i = 0; i < n; ++i) {
        int mem_depth, depth = 0;
        int node = i + 1;

        while (a[node - 1] != -1) {
            node = a[node - 1];

            mem_depth = findDepth(depths, node);
            if (mem_depth != -1) {
                depth += mem_depth + 1;
                break;
            }

            ++depth;
        }

        depths[i + 1] = depth;

        res = max(res, depth + 1);
    }
    cout << res << "\n";

    return 0;
}
