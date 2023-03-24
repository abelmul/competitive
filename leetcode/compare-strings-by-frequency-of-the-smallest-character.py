from typing import List


class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        def f(word: str):
            l = len(word)

            min_char = word[0]
            d = {word[0]: 1}

            for i in range(1, l):
                if word[i] == min_char:
                    d[min_char] += 1
                elif word[i] < min_char:
                    del d[min_char]
                    min_char = word[i]
                    d[min_char] = 1

            return d[min_char]

        length = len(words)
        words_f = sorted([f(w) for w in words])

        res = [0] * len(queries)

        for i, q in enumerate(queries):
            f_q = f(q)
            l = 0
            r = length

            while l < r:
                m = (l + r) // 2

                if words_f[m] > f_q:
                    r = m
                else:
                    l = m + 1

            res[i] = length - l

        return res
