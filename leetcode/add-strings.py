class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        carry = 0

        res = ""

        i = len(num1) - 1
        j = len(num2) - 1

        def add(num1, num2, carry):
            s = carry + int(num1) + int(num2)

            return s % 10, s // 10

        while i >= 0 and j >= 0:
            s, carry = add(num1[i], num2[j], carry)

            res += str(s)
            i -= 1
            j -= 1

        while i >= 0:
            s, carry = add(num1[i], 0, carry)

            res += str(s)
            i -= 1

        while j >= 0:
            s, carry = add(num2[j], 0, carry)

            res += str(s)
            j -= 1

        if carry > 0:
            res += str(carry)

        return res[::-1]
