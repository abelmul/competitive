class Solution:
    def minSwaps(self, s: str) -> int:
        opening_brackets = 0
        closing_brackets = 0

        swaps = 0

        for c in s:
            if c == "[":
                opening_brackets += 1
            else:
                closing_brackets += 1

                if closing_brackets > opening_brackets:
                    swaps += 1
                    closing_brackets -= 1
                    opening_brackets += 1

        return swaps
