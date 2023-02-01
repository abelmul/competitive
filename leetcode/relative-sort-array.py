from typing import List


class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        # freq = collections.Counter(arr1)

        # res = []

        # for a in arr2:
        #     res.extend([a] * freq[a])
        #     del freq[a]

        # not_in_arr2 = []
        # for k,v in freq.items():
        #     not_in_arr2.extend([k]*v)

        # return res + sorted(not_in_arr2)

        arr2_dict = {v: i for i, v in enumerate(arr2)}

        def comp(x):
            if x in arr2_dict:
                return arr2_dict[x]
            return 1000 + x

        return sorted(arr1, key=comp)
