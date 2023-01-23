from typing import List


class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        power_of_two = [2**i for i in range(22)]
        deliciousness_dict = {}

        ans = 0
        for d in deliciousness:
            for power in power_of_two:
                if power - d in deliciousness_dict:
                    ans += deliciousness_dict[power - d]
            deliciousness_dict[d] = deliciousness_dict.get(d, 0) + 1

        return ans % (10**9 + 7)
