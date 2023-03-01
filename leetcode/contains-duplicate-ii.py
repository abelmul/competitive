class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        d = {}

        for i, n in enumerate(nums):
            if n not in d:
                d[n] = i
            elif abs(d[n] - i) <= k:
                return True
            else:
                d[n] = i

        return False
