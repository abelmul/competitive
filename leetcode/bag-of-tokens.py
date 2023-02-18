from typing import List


class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        left = score = 0
        right = len(tokens) - 1

        tokens.sort()

        while left <= right:
            if power >= tokens[left]:
                power -= tokens[left]
                score += 1

                left += 1
            elif score > 0 and left != right:
                power += tokens[right]
                score -= 1

                right -= 1

            else:
                break

        return score
