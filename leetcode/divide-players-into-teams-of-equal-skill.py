from typing import List


class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()

        l = 0
        r = len(skill) - 1

        total_skill = skill[l] + skill[r]
        found_error = False
        chemistry = 0

        while l < r:
            current_total = skill[l] + skill[r]

            if total_skill != current_total:
                found_error = True
                break

            chemistry += skill[l] * skill[r]

            l += 1
            r -= 1

        return chemistry if not found_error else -1
