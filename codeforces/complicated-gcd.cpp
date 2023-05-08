#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;

    if (a != b) {
        cout << 1;
    } else {
        cout << a;
    }
    cout << "\n";

    return 0;
}
