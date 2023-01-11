from typing import List

class Solution:
    def similarPairs(self, words: List[str]) -> int:
        count = 0
        words_set = [set(w) for w in words]

        for i,w in enumerate(words_set):
            for j in range(i+1, len(words_set)):
                if i != j and w == words_set[j]:
                    count += 1
        return count
