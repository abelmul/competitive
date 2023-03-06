class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d = {}
        length = len(s)
        max_substring = 0

        prev_index = 0
        i = 0

        while i < length:
            d[s[i]] = d.get(s[i], 0) + 1

            if d[s[i]] > 1:
                max_substring = max(max_substring, i - prev_index)

                while d[s[i]] > 1:
                    d[s[prev_index]] -= 1 if d[s[prev_index]] > 0 else 0
                    prev_index += 1
            i += 1

        return max(max_substring, i - prev_index)
