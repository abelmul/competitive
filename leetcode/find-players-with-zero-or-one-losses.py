from typing import List


class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        wins = {}
        losses = {}

        for w, l in matches:
            wins[w] = 1
            losses[l] = losses.get(l, 0) + 1

        one_loss = []

        for k, v in losses.items():
            if k in wins:
                del wins[k]

            if v == 1:
                one_loss.append(k)

        return [sorted(wins.keys()), sorted(one_loss)]
