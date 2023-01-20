class Solution:
    def freqAlphabets(self, s: str) -> str:
        length = len(s)
        i = 0

        decrypted = ""

        while i < length:
            if i + 2 < length and s[i + 2] == "#":
                decrypted += chr(ord("a") + int(s[i] + s[i + 1]) - 1)
                i += 3
            else:
                decrypted += chr(ord("a") + int(s[i]) - 1)
                i += 1

        return decrypted
