from typing import List


class Solution:
    def partitionLabels(self, s: str) -> List[int]:

        intervals = {}
        length = len(s)

        for i in range(length):
            if s[i] in intervals:
                continue

            r = length - 1

            while i <= r:
                if s[r] == s[i]:
                    break
                r -= 1

            intervals[s[i]] = [i, r]

        merged_intervals = []
        current_interval = []

        for i in intervals.values():
            if current_interval == []:
                current_interval = i
                continue

            if i[0] < current_interval[1] and i[1] > current_interval[1]:
                current_interval[1] = i[1]

            if i[1] > current_interval[1]:
                merged_intervals.append(current_interval[1] - current_interval[0] + 1)
                current_interval = i

        merged_intervals.append(current_interval[1] - current_interval[0] + 1)

        return merged_intervals
