# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:


class Solution:
    def firstBadVersion(self, n: int) -> int:
        l = 1
        r = n

        while l < r:
            m = l + (r - l) // 2

            isBad = isBadVersion(m)

            if not isBad:
                l = m + 1
            else:
                r = m

        return l
