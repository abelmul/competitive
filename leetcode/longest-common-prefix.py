class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ""
        min_length = 201

        for s in strs:
            min_length = min(min_length, len(s))

        for i in range(min_length):
            c = strs[0][i]
            breaked = False

            for j in range(1, len(strs)):
                s = strs[j]

                if s[i] != c:
                    breaked = True
                    break

            if breaked:
                break
            else:
                prefix += c

        return prefix

