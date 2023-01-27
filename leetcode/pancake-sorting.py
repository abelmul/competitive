from typing import List


class Solution:
    @staticmethod
    def maxIndex(arr: List[int], until: int):
        index = 0
        for i in range(1, until):
            if arr[i] > arr[index]:
                index = i

        return index

    @staticmethod
    def flipSequence(arr: List[int], a: int, b: int):
        while a < b:
            arr[a], arr[b] = arr[b], arr[a]

            a += 1
            b -= 1

    def pancakeSort(self, arr: List[int]) -> List[int]:
        """
        as reverse selection sort
        """
        length = len(arr)
        res = []
        for i in range(length, 1, -1):
            max_index = Solution.maxIndex(arr, i)
            Solution.flipSequence(arr, 0, max_index)
            Solution.flipSequence(arr, 0, i - 1)
            res.append(max_index + 1)
            res.append(i)

        return res
