class Solution:
    def decodeString(self, s: str) -> str:
        if len(s) <= 1:
            return s

        stack = []
        length = len(s)
        i = 0

        while i < length:
            stack.append(i)

            if s[i] == "]":
                j = -1
                while stack and s[stack[-1]] != "[":
                    j = stack.pop()

                # remove "["
                stack.pop()

                # get number
                number = ""
                while stack and 48 <= ord(s[stack[-1]]) <= 57:
                    number += s[stack.pop()]

                number_len = len(number)
                number = int(number[::-1])

                decoded = self.decodeString(s[j:i])

                s = s[: j - number_len - 1] + number * decoded + s[i + 1 :]

                length = len(s)
                i = j - number_len - 2

            i += 1

        return s
