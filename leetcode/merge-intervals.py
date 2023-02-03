from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)

        length = len(intervals)

        res = []
        start = 0
        end = 0

        for i in range(1, length):
            if intervals[i][0] <= intervals[end][1]:
                if intervals[i][1] > intervals[end][1]:
                    end = i
                continue

            res.append([intervals[start][0], intervals[end][1]])
            start = i
            end = i
        res.append([intervals[start][0], intervals[end][1]])
        return res
