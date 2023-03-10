from functools import cmp_to_key, partial
from typing import List


class Solution:
    def compare_by(self, order, str1, str2):
        if str1 == str2:
            return 0

        # calculate length of the strings
        length1 = len(str1)
        length2 = len(str2)
        length = min(length1, length2)

        for i in range(length):
            index1 = order.index(str1[i])
            index2 = order.index(str2[i])

            if index1 > index2:
                return 1
            elif index1 < index2:
                return -1

        if length == length1:
            return -1
        else:
            return 1

    def isAlienSorted(self, words: List[str], order: str) -> bool:
        return words == sorted(words, key=cmp_to_key(partial(self.compare_by, order)))
