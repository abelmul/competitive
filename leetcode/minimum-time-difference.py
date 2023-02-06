from typing import List


class Solution:
    def getByMinute(self, timepoint):

        return int(timepoint[0]) * 60 + int(timepoint[1])

    def findMinDifference(self, timePoints: List[str]) -> int:
        timePoints.sort()
        length = len(timePoints)

        last = self.getByMinute(timePoints[-1].split(":"))

        hour_24 = 24 * 60
        min_minute = int("inf")

        for i in range(1, length):
            first = self.getByMinute(timePoints[i - 1].split(":"))
            second = self.getByMinute(timePoints[i].split(":"))

            min_minute = min(
                min_minute, min(abs(first - second), abs(hour_24 - second + first))
            )

        first = self.getByMinute(timePoints[0].split(":"))
        min_minute = min(
            min_minute, min(abs(first - last), abs(hour_24 - last + first))
        )

        return min_minute
