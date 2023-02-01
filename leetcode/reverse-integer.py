class Solution:
    def reverse(self, x: int) -> int:
        numbers = []
        negative = False if x >= 0 else True

        x = abs(x)

        while x != 0:
            numbers.append(x % 10)
            x //= 10

        length = len(numbers)
        number = 0

        for i in range(length):
            number += numbers[i] * 10 ** (length - i - 1)

        if negative:
            number = -number

        if number > 2147483647 or number < -2147483648:
            number = 0

        return number
