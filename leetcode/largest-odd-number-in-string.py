class Solution:
    def largestOddNumber(self, num: str) -> str:
        # find the last odd number
        l = len(num) - 1

        while l >= 0:
            if int(num[l]) % 2 != 0:
                break
            l -= 1

        return num[: l + 1]
