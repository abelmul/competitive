class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        length = len(s)

        cur_cost = l = res = 0

        for r in range(length):
            cur_cost += abs(ord(s[r]) - ord(t[r]))

            while cur_cost > maxCost:
                cur_cost -= abs(ord(s[l]) - ord(t[l]))
                l += 1

            res = max(res, r - l + 1)

        return res
