from typing import List


class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:

        carry = 0
        r = len(num) - 1
        res = []

        while r >= 0 or k > 0:
            n = 0
            if r >= 0:
                n = num[r]
                r -= 1

            s = k % 10 + n + carry
            carry = 0

            if s >= 10:
                carry = s // 10
                s = s % 10

            res.append(s)
            k //= 10

        if carry > 0:
            res.append(carry)

        res.reverse()

        return res
