from typing import List


class TopVotedCandidate:
    def __init__(self, persons: List[int], times: List[int]):
        self.length = len(persons)

        self.max_vote = [-1] * self.length

        counter = {persons[0]: 1}
        self.max_vote[0] = persons[0]

        for i in range(1, self.length):
            counter[persons[i]] = counter.get(persons[i], 0) + 1

            if counter[persons[i]] >= counter[self.max_vote[i - 1]]:
                self.max_vote[i] = persons[i]
            else:
                self.max_vote[i] = self.max_vote[i - 1]

        self.times = times

    def q(self, t: int) -> int:
        # binary search for index where t <= times[i]
        l = 0
        r = self.length

        while l < r:
            m = (l + r) // 2

            if t > self.times[m]:
                l = m + 1
            else:
                r = m
        if l < self.length and self.times[l] == t:
            return self.max_vote[l]
        else:
            return self.max_vote[l - 1]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
