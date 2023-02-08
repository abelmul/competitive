from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1

        max_area = 0  # min(heights[l], heights[r]) * len(height) # (r - l + 1)

        while l < r:
            min_height = min(height[l], height[r])
            max_area = max(max_area, min_height * (r - l))

            if min_height == height[l]:
                l += 1
            else:
                r -= 1

        return max_area
