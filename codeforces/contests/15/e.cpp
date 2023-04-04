#include <bits/stdc++.h>

#include <utility>

/**
 * Kefa and Park
 * https://codeforces.com/gym/436386/problem/E
 * Time - O(n)
 * Space - O(n) - for stack and set
 */

using namespace std;

int countAvailableResturants(vector<vector<int>>& adjlist, vector<int>& cats,
                             int m)
{
    int count = 0;
    bool isleaf;
    int node, cats_count, conseq_cats;

    // dfs
    stack<pair<int, int>> s;
    set<int> visited;

    s.push(make_pair(1, 0));

    while (!s.empty()) {
        tie(node, cats_count) = s.top();
        isleaf = true;

        s.pop();

        if (cats_count + cats[node - 1] > m)
            continue;

        for (auto a : adjlist[node - 1]) {
            if (visited.find(a) == visited.end()) {
                conseq_cats = cats_count;
                if (cats[node - 1])
                    ++conseq_cats;
                else
                    conseq_cats = 0;

                s.push(make_pair(a, conseq_cats));
                isleaf = false;
            }
        }

        visited.insert(node);

        if (isleaf) {
            // found a leaf node
            ++count;
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> adjlist;
    vector<int> cats;
    int n, m;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    cats.resize(n);
    adjlist.resize(n);

    for (auto i = 0; i < n; ++i) cin >> cats[i];

    for (auto i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;
        adjlist[v - 1].push_back(u);
        adjlist[u - 1].push_back(v);
    }

    cout << countAvailableResturants(adjlist, cats, m) << "\n";

    return 0;
}
