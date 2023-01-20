class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        l = set(nums)

        for i in nums:
            l.add(int(str(i)[::-1]))  # alternative [::-1]

        return len(l)
