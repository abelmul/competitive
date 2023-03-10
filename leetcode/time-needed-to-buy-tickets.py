from typing import List


class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        seconds = 0
        length = len(tickets)

        i = 0

        while True:
            if tickets[i] > 0:
                tickets[i] -= 1
                seconds += 1

            if i == k and tickets[i] <= 0:
                break

            i = (i + 1) % length

        return seconds
