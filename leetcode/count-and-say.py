class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        s = self.countAndSay(n - 1)

        res = []
        length = len(s)
        i = 0

        while i < length:
            count = 0
            c = s[i]

            while i < length:
                if s[i] != c:
                    break

                count += 1
                i += 1
            res.append(f"{count}{c}")

        return "".join(res)
