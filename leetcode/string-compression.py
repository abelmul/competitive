from typing import List

class Solution:
    def compress(self, chars: List[str]) -> int:
        placeholder = 0
        seeker = 1
        length = len(chars)

        pos = 0

        while seeker < length + 1:
            if seeker < length and chars[placeholder] == chars[seeker]:
                seeker += 1
                continue

            group_len = seeker - placeholder
            chars[pos] = chars[placeholder]

            if seeker - placeholder > 1:
                group_len = str(seeker - placeholder)
                for c in group_len:
                    chars[pos + 1] = c
                    pos += 1

            placeholder = seeker
            seeker += 1
            pos += 1

        return pos
