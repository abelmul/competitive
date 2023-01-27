from typing import List


class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        d = {}
        for i, h in enumerate(heights):
            if h not in d:
                d[h] = []

            d[h].append(names[i])

        heights.sort(reverse=True)

        res = []

        for h in heights:
            res.extend(d[h])

        return res
