#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    unsigned long long a, b, c, d;
    unsigned long long g, num, dino;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> a >> b >> c >> d;

        num = a * d;
        dino = b * c;

        if (num == dino) {
            cout << 0;
        }
        else if (num == 0 || dino == 0 || num % dino == 0 || dino % num == 0) {
            cout << 1;
        } else {
            cout << 2;
        }

        cout << "\n";
    }

    return 0;
}
