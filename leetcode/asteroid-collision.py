from typing import List


class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []

        for a in asteroids:
            add_to_stack = True
            while stack and a < 0 and stack[-1] > 0:
                if abs(a) == stack[-1]:
                    add_to_stack = False
                    stack.pop()
                    break
                elif abs(a) > stack[-1]:
                    stack.pop()
                else:
                    add_to_stack = False
                    break

            if add_to_stack:
                stack.append(a)

        return stack
