from typing import Counter


class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        st = []  # min stack
        letters = Counter(s)

        for c in s:
            while st and c not in st and c < st[-1] and letters[st[-1]] > 0:
                st.pop()

            letters[c] -= 1
            if c not in st:
                st.append(c)
        return "".join(st)
