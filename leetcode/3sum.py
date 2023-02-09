from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        length = len(nums)

        res = set()
        prev = 100001  # see constraint

        for i in range(length):
            if nums[i] == prev:
                continue

            if nums[i] > 0:
                break

            x = nums[i]
            l = i + 1
            r = length - 1

            while l < r:
                s = x + nums[l] + nums[r]
                if s == 0:
                    res.add((x, nums[l], nums[r]))
                    l += 1
                    r -= 1
                elif s > 0:
                    r -= 1
                else:
                    l += 1

            prev = nums[i]

        return list(res)
