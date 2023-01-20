from typing import List


class Solution:
    def commonChars(self, words: List[str]) -> List[str]:

        letters = [0] * 26
        offset = ord("a")

        for c in words[0]:
            letters[ord(c) - offset] += 1

        for w in range(1, len(words)):
            temp = [0] * 26
            for c in words[w]:
                temp[ord(c) - offset] += 1

            for i in range(26):
                letters[i] = min(temp[i], letters[i])

        res = []

        for i in range(26):
            if letters[i] != 0:
                res.extend([chr(i + offset)] * letters[i])

        return res
