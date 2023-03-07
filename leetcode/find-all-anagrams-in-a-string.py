from collections import Counter
from typing import List


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        length = len(s)
        k = len(p)

        anagram_c = Counter(p)
        str_c = Counter(s[:k])

        res = []
        if anagram_c == str_c:
            res.append(0)

        for i in range(1, length - k + 1):
            str_c[s[i - 1]] -= 1
            str_c[s[i + k - 1]] += 1
            if anagram_c == str_c:
                res.append(i)

        return res
