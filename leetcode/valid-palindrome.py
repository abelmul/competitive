class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join([c.lower() for c in s if c.isalnum()])
        print(s)

        begin = 0
        end = len(s) - 1

        while begin < end:
            if s[begin] != s[end]:
                return False

            begin += 1
            end -= 1

        return True
