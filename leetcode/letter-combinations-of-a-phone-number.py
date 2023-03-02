from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        table = {
            "2": ["a", "b", "c"],
            "3": ["d", "e", "f"],
            "4": ["g", "h", "i"],
            "5": ["j", "k", "l"],
            "6": ["m", "n", "o"],
            "7": ["p", "q", "r", "s"],
            "8": ["t", "u", "v"],
            "9": ["w", "x", "y", "z"],
        }

        res = []

        for d in digits:
            current = []

            for c in table[d]:
                if len(res) > 0:
                    for r in res:
                        current.append(r + c)
                else:
                    current.append(c)

            res = current

        return res
