from typing import List


class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        dictionary = sorted(dictionary, key=lambda s: (-len(s), s))

        s_length = len(s)

        for d in dictionary:
            placeholder = 0
            seeker = 0
            d_length = len(d)

            if d_length > s_length:
                continue

            while placeholder < d_length:
                while seeker < s_length and s[seeker] != d[placeholder]:
                    seeker += 1

                if seeker == s_length:
                    break

                placeholder += 1
                seeker += 1

            if placeholder == d_length:
                return d

        return ""
