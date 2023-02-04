from typing import List


class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        max_sum = 0
        n = len(accounts)

        for i in range(n):
            max_sum = max(max_sum, sum(accounts[i]))

        return max_sum
