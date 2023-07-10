from typing import List


class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        if len(changed) % 2 != 0:
            return []

        res = []
        d = {}

        changed.sort()
        for c in changed:
            if c % 2 == 0 and c // 2 in d:
                res.append(c // 2)

                d[c // 2] -= 1
                if d[c // 2] == 0:
                    del d[c // 2]
            else:
                d[c] = d.get(c, 0) + 1

        return res if len(res) * 2 == len(changed) else []
