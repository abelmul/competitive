from typing import List


class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        """
        if an element is minimum over range i,l
        where i is the begining and l is the end
        it will be in subarrays
        (l - (i+1)) * (j-i)
        """
        length = len(arr)

        res = 0
        min_stack = []

        for i in range(length):
            while min_stack and arr[min_stack[-1]] > arr[i]:
                j = min_stack.pop()
                """
                this subarray is minimum over all of
                last_j,...,j,...,i
                length = i - (last_j+1)
                for 0 it must be -1

                j = j - (last_j + 1)
                """
                last_j = min_stack[-1] if min_stack else -1
                res += (i - j) * (j - last_j) * arr[j]

            min_stack.append(i)

        """
        all items in the stack are minimum over
        last_j,....,j,....length
        """
        last_j = -1
        for j in min_stack:
            res += (length - j) * (j - last_j) * arr[j]
            last_j = j

        return res % (10**9 + 7)
