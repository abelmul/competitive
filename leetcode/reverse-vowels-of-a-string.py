class Solution:
    def reverseVowels(self, i: str) -> str:
        s = list(i)
        l = 0
        r = len(s) - 1

        vowels = {"a", "e", "i", "o", "u"}

        while l < r:
            if s[l].lower() in vowels and s[r].lower() in vowels:
                s[l], s[r] = s[r], s[l]
                l += 1
                r -= 1
                continue

            if s[l].lower() not in vowels:
                l += 1

            if s[r].lower() not in vowels:
                r -= 1

        return "".join(s)
