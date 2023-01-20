class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        d = [i for i in range(1, n + 1)]

        count = 0
        remaining = n
        while len(d) != 1:
            count = (count + k - 1) % remaining
            remaining -= 1

            d.pop(count)

        return d[0]
