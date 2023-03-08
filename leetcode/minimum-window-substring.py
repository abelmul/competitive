from collections import Counter


class Solution:
    def has_substring(self, s_cnt, t_cnt):
        for k, v in t_cnt.items():
            if k not in s_cnt or s_cnt[k] < v:
                return False
        return True

    def minWindow(self, s: str, t: str) -> str:
        m = len(s)

        t_cnt = Counter(t)
        s_cnt = Counter()
        res = None
        l = 0

        for r in range(m):
            s_cnt[s[r]] += 1
            found_substring = False

            while self.has_substring(s_cnt, t_cnt):
                found_substring = True
                s_cnt[s[l]] -= 1
                l += 1

            if found_substring:
                l -= 1
                s_cnt[s[l]] += 1
                if res == None or len(res) > r - l + 1:
                    res = s[l : r + 1]

        return res or ""
