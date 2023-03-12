class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        min_stack = []

        for n in num:
            while k and min_stack and min_stack[-1] > n:
                min_stack.pop()
                k -= 1

            min_stack.append(n)

        if k > 0:
            min_stack = min_stack[:-k]

        while min_stack and min_stack[0] == "0":
            min_stack = min_stack[1:]

        return "".join(min_stack) or "0"
