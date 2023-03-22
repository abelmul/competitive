from typing import List


class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        length = len(intervals)
        d = {intervals[i][0]: i for i in range(length)}
        intervals.sort(key=lambda x: x[0])

        def binarySearch(target):
            l = 0
            r = length

            while l < r:
                m = (l + r) // 2

                if intervals[m][0] < target:
                    l = m + 1
                else:
                    r = m

            return l

        res = [-1] * length
        for interval in intervals:
            n = binarySearch(interval[1])
            if n < length:
                res[d[interval[0]]] = d[intervals[n][0]]

        return res
