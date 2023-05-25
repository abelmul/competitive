#include <bits/stdc++.h>

using namespace std;

/**
 * Shortest path of the king
 * https://codeforces.com/gym/444629/problem/B
 *
 * Time - O(1)
 * Space - O(1)
 */

unordered_map<string, pair<int, int>> dirs = {
    {"LU", {-1, 1}}, {"U", {0, 1}},    {"RU", {1, 1}}, {"L", {-1, 0}},
    {"R", {1, 0}},   {"LD", {-1, -1}}, {"D", {0, -1}}, {"RD", {1, -1}},
};

inline long long dist(pair<int, int> pos, const pair<int, int> t)
{
    return pow(pos.first - t.first, 2) + pow(pos.second - t.second, 2);
}

vector<tuple<int, int, string>> get_move_pos(pair<int, int> pos, const pair<int, int> t)
{
    vector<tuple<int, int, string>> res;
    int row, col;

    for (auto& [k, v] : dirs) {
        row = pos.first + v.first;
        col = pos.second + v.second;

        if (row >= 0 && row < 8 && col >= 0 && row < 8 && dist({row, col}, t) < dist(pos, t)) {
            res.push_back({row, col, k});
        }
    }

    sort(res.begin(), res.end(), [&t](auto t1, auto t2) {
        return dist({get<0>(t1), get<1>(t1)}, t) < dist({get<0>(t2), get<1>(t2)}, t);
    });

    return res;
}

int dfs(pair<int, int> king_pos, pair<int, int> t_pos, set<pair<int, int>>& visited,
        vector<string>& ans)
{
    if (visited.find(king_pos) != visited.end())
        return -1;

    int res = 0;
    int tmp;

    if (king_pos != t_pos) {
        for (auto p : get_move_pos(king_pos, t_pos)) {
            tmp = dfs({get<0>(p), get<1>(p)}, t_pos, visited, ans);
            if (tmp != -1) {
                res = 1 + tmp;
                ans.push_back(get<2>(p));
                break;
            }
        }
    }

    return res;
}

int main()
{
    string k, t;

    pair<int, int> king_pos, t_pos;
    vector<string> path;
    set<pair<int, int>> visited;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    cin >> t;

    king_pos = make_pair(k[0] - 'a', k[1] - '1');
    t_pos = make_pair(t[0] - 'a', t[1] - '1');

    cout << dfs(king_pos, t_pos, visited, path) << "\n";

    for (auto i = path.rbegin(); i < path.rend(); ++i) cout << *i << "\n";

    return 0;
}
