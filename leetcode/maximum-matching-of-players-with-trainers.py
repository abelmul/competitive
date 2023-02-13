from typing import List


class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()

        trainers_ptr = 0
        players_ptr = 0
        trainers_last = len(trainers)
        players_last = len(players)

        max_matchings = 0

        while trainers_ptr < trainers_last and players_ptr < players_last:
            if trainers[trainers_ptr] < players[players_ptr]:
                trainers_ptr += 1
                continue

            max_matchings += 1
            players_ptr += 1
            trainers_ptr += 1

        return max_matchings
