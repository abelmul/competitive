from typing import List


class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        position_speed = sorted(zip(position, speed), reverse=True)

        stack = []

        for p, s in position_speed:
            time = (target - p) / s
            if stack and stack[-1] >= time:
                continue

            stack.append(time)

        return len(stack)
