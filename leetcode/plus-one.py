from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits.reverse()

        for i in range(len(digits)):
            digits[i] = digits[i] + 1 if digits[i] != 9 else 0
            if digits[i] != 0:
                break

        if digits[-1] == 0:
            digits.append(1)

        digits.reverse()

        return digits
