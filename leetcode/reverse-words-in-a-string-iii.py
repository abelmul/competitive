class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        length = len(words)

        for i in range(length):
            words[i] = words[i][::-1]

        return " ".join(words)
