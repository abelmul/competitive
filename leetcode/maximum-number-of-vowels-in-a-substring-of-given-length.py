class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        length = len(s)
        vowels = {"a", "e", "i", "o", "u"}

        max_vowels = n_vowels = 0

        for i in range(k):
            if s[i] in vowels:
                n_vowels += 1

        max_vowels = n_vowels

        for i in range(k, length):
            if s[i - k] in vowels:
                n_vowels -= 1

            if s[i] in vowels:
                n_vowels += 1

            max_vowels = max(max_vowels, n_vowels)

        return max_vowels
