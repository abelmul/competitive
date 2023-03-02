#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    string sortSentence(string s)
    {
        string sentence = "";
        int spaces = 0;

        for (auto c : s) {
            if (c == ' ')
                ++spaces;
        }
        ++spaces;

        for (int i = 0; i < spaces; ++i) {
            size_t start = 0;
            size_t end = 0;

            if (s.back() - '0' == i + 1) {
                start = s.rfind(" ", string::npos);
                s.pop_back();
                sentence += s.substr(start + 1, s.size());
                if (i != spaces - 1) {
                    sentence += " ";
                }
            } else {
                while ((end = s.find(" ", start)) != string::npos) {
                    if (s[end - 1] - '0' == i + 1) {
                        sentence += s.substr(start, end - 1 - start);

                        if (i != spaces - 1) {
                            sentence += " ";
                        }
                    }
                    start = end + 1;
                }
            }
        }

        return sentence;
    }
};
