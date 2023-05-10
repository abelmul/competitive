class Solution
{
 public:
    bool isNice(const string& s, const set<char>& ss, int l, int r)
    {
        char c;
        for (auto i = l; i < r; ++i) {
            c = s[i];
            if ((isupper(c) && ss.find(tolower(c)) == ss.end()) ||
                (islower(c) && ss.find(toupper(c)) == ss.end()))
                return false;
        }

        return true;
    }

    string longestNiceSubstring(string s)
    {
        auto size = s.size();

        function<string(int, int)> helper = [&](int l, int r) {
            // divide and conquer
            string left, right;
            char c;

            set<char> ss;

            for (auto i = l; i < r; ++i) ss.insert(s[i]);

            for (auto i = l; i < r; ++i) {
                c = s[i];
                if ((isupper(c) && ss.find(tolower(c)) == ss.end()) ||
                    (islower(c) && ss.find(toupper(c)) == ss.end())) {
                    left = helper(l, i);
                    right = helper(i + 1, r);

                    if (left.size() >= right.size()) {
                        return left;
                    } else {
                        return right;
                    }
                }
            }

            return s.substr(l, r - l);
        };

        /**
          // bruteforce
          for (auto i = 0; i < size; ++i) {
              ss.insert(s[i]);
              for (auto j = i + 1; j < size; ++j) {
                  ss.insert(s[j]);
                  if (isNice(s, ss, i, j + 1)) {
                      if (res.size() < j - i + 1) {
                          res = s.substr(i, j - i + 1);
                      }
                  }
              }
              ss.clear();
          }
        */

        return helper(0, s.size());
    }
};