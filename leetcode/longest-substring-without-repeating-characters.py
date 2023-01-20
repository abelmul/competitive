class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxcount = 0
        word = ""
        for char in s:
            if char in word:
                maxcount = max(maxcount, len(word))
                word = word[word.index(char) + 1 :]
            word += char
        return max(maxcount, len(word))
