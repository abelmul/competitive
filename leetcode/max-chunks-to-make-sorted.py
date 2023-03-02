class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        chunks = 0
        max_num = -1
        length = len(arr)

        for i in range(length):
            max_num = max(max_num, arr[i])
            if max_num == i:
                chunks += 1

        return chunks
