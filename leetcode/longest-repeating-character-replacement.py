from collections import Counter


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        str_cnt = Counter()

        length = len(s)
        max_length = 0
        max_freq = 0
        l = 0

        for i in range(length):
            str_cnt[s[i]] += 1
            max_freq = max(max_freq, str_cnt[s[i]])

            while (i - l + 1) - max_freq > k:
                str_cnt[s[l]] -= 1
                max_freq = max(str_cnt.values())
                l += 1

            max_length = max(max_length, i - l + 1)

        return max_length
