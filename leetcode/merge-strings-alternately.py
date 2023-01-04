class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        length = min(len(word1), len(word2))

        result = ""
        for i in range(length):
            result += word1[i]
            result += word2[i]

        result += word1[length:]
        result += word2[length:]

        return result
