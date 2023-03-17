from typing import List


class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        delta = [0] * (n + 1)

        for first, last, seats in bookings:
            delta[first - 1] += seats
            delta[last] -= seats

        # calculate presum
        for i in range(1, n + 1):
            delta[i] += delta[i - 1]

        return delta[:n]
