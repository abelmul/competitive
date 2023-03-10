from typing import List


class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        s = set()

        for a in arr:
            if 2 * a in s:
                return True
            elif a % 2 == 0 and a // 2 in s:
                return True

            s.add(a)

        return False
