class Solution:
    # not used just for reference
    def getGrammar(self, n) -> str:
        if n <= 1:
            return "0"

        prev = self.getGrammar(n - 1)

        if n % 2 == 0:
            return prev + prev.replace("1", "2").replace("0", "1").replace("2", "0")
        else:
            return prev + prev[::-1]

    def kthGrammar(self, n: int, k: int) -> int:
        if k == 1:
            return 0

        # length of n and n-1 string
        length = 1 << (n - 1)
        half_l = length >> 1
        diff = 0

        while k <= half_l:
            diff += 1
            half_l = half_l >> 1

        if diff != 0:
            return self.kthGrammar(n - diff, k)

        if n % 2 == 1:
            # if it is odd we just reverse the string
            return self.kthGrammar(n - 1, (length - k) % half_l + 1)
        else:
            # if it is even we invert it
            k = k % half_l
            return 1 - self.kthGrammar(n - 1, k if k != 0 else half_l)
