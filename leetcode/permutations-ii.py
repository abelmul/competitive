from typing import List, Set


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        length = len(nums)
        res = []

        nums.sort()

        def backtrack(used_idx: Set[int], cur: List[int]):
            if len(cur) == length:
                res.append(cur.copy())
                return

            for i in range(length):
                if i not in used_idx and (
                    i < 1 or (nums[i] != nums[i - 1] or i - 1 in used_idx)
                ):
                    cur.append(nums[i])
                    used_idx.add(i)

                    backtrack(used_idx, cur)

                    used_idx.remove(i)
                    cur.pop()

        backtrack(set(), [])

        return res
