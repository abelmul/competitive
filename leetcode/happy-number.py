class Solution:
    def isHappy(self, n: int) -> bool:
        d = {}
        res = n

        def calculate_square_sum(n: int):
            s = str(n)
            prod_sum = 0

            for c in s:
                prod_sum += int(c) ** 2

            return prod_sum

        while res not in d:
            n = res
            res = calculate_square_sum(n)

            if res == 1:
                return True

            d[n] = res

        return False
