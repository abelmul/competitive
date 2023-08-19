#include <bits/stdc++.h>

using namespace std;

bool is_divisible_by_8(string s) {
    auto size = s.size();
    int value  = 0;

    if (size == 0) {
        return false;
    }

    if (size >= 1) {
        value += (s[size-1] - '0');
    }

    if (size >= 2) {
        value += (s[size-2] - '0') * 10;
    }

    if (size >= 3) {
        value += (s[size-3] - '0') * 100;
    }

    return value % 8 == 0;
}

int main()
{
    string s;
    int n;
    string res = "";

    unordered_map<string, string> memo;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin  >> s;

    n = s.size();

    return 0;
}
