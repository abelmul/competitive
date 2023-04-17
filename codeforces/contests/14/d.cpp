#include <bits/stdc++.h>

using namespace std;

/**
 * Catch Overflow
 * https://codeforces.com/gym/434753/problem/D
 *
 * Time - O(n)
 * Space - O(n) - for stack
 */

void solve(int n)
{
    stack<pair<unsigned long long, int>> st;
    string command;
    unsigned long long result;

    constexpr unsigned long long LIMIT = 4294967295;

    int cmd, loop;

    bool overflow = false;

    st.push(make_pair(0, 0));

    for (auto i = 0; i < n; ++i) {
        cin >> command;

        if (command == "add") {
            tie(result, cmd) = st.top();
            if (cmd == 0) {
                st.pop();
                if (result + 1 > LIMIT) {
                    overflow = true;
                    break;
                }
                st.push(make_pair(result + 1, cmd));
            } else {
                st.push(make_pair(1, 0));
            }
        } else if (command == "for") {
            cin >> loop;
            st.push(make_pair(loop, 1));
        } else {
            // "end"
            // traverse until we get a cmd == 1
            tie(result, cmd) = st.top();
            st.pop();
            if (cmd == 1) {
                continue;
            }

            result *= st.top().first;
            st.pop();
            while (!st.empty() && st.top().second == 0) {
                result += st.top().first;
                st.pop();
            }

            if (result > LIMIT) {
                overflow = true;
                break;
            }
            st.push(make_pair(result, 0));
        }
    }

    if (overflow) {
        cout << "OVERFLOW!!!";
    } else {
        cout << st.top().first;
    }
    cout << "\n";
}

int main()
{
    int n;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    solve(n);

    return 0;
}
