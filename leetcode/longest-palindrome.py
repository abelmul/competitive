class Solution:
    def longestPalindrome(self, s: str) -> int:
        counter = {}

        for c in s:
            counter[c] = counter.get(c, 0) + 1

        largest_palindrom = 0
        add_one = 0
        # print(counter)
        for v in counter.values():
            if v % 2 == 1:
                add_one = 1
            largest_palindrom += v - v % 2

        return largest_palindrom + add_one
