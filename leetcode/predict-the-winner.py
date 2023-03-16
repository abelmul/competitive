from functools import lru_cache
from typing import List


class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        @lru_cache(maxsize=1000)
        def canBeAWinner(l: int, r: int, player1s_turn: bool) -> int:
            if l == r:
                return 0

            # take first or last
            score = max(
                nums[l] - canBeAWinner(l + 1, r, not player1s_turn),
                nums[r - 1] - canBeAWinner(l, r - 1, not player1s_turn),
            )

            return score

        return canBeAWinner(0, len(nums), True) >= 0
