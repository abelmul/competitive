class Solution:
    def lastRemaining(self, n: int) -> int:
        if n == 1:
            return 1

        def helper(left: int, right: int, diff: int, left_to_right: bool):
            if left == right:
                return left

            if ((right - left) // diff + 1) % 2 == 1:
                # we subtract from both left and right
                left += diff
                right -= diff
            elif left_to_right:
                left += diff
            else:
                right -= diff

            return helper(left, right, diff * 2, not left_to_right)

        return helper(1, n, 1, True)
