import operator
from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        ops = {
            "+": operator.add,
            "-": operator.sub,
            "*": operator.mul,
            "/": lambda a, b: int(float(a) / b),
        }

        for token in tokens:
            if token in ops:
                second = int(stack.pop())
                first = int(stack.pop())
                token = str(ops[token](first, second))

            stack.append(token)

        return int(stack[-1])
