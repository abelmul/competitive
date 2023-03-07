from collections import Counter


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        length = len(s2)
        k = len(s1)

        anagram_ctn = Counter(s1)
        str_ctn = Counter()

        for i in range(length):
            str_ctn[s2[i]] += 1
            if i >= k:
                str_ctn[s2[i - k]] -= 1

            if anagram_ctn == str_ctn:
                return True

        return False
