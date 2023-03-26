from typing import List


class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        length = len(weights)

        def isEnough(capacity: int):
            total = 0
            day = 0

            for i in range(length):
                if weights[i] > capacity or day > days:
                    return False

                if total + weights[i] > capacity:
                    total = 0
                    day += 1

                total += weights[i]

            return days >= day + 1 if total > 0 else 0

        l = 1
        r = sum(weights)

        while l < r:
            m = (l + r) // 2

            if isEnough(m):
                r = m
            else:
                l = m + 1

        return l
