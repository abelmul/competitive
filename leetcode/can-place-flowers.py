from typing import List


class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        length = len(flowerbed)

        # for 0
        if flowerbed[0] == 0 and (length == 1 or (length > 1 and flowerbed[1] == 0)):
            flowerbed[0] = 1
            n -= 1

        for i in range(1, length - 1):
            if flowerbed[i] == 0 and flowerbed[i - 1] == 0 and flowerbed[i + 1] == 0:
                flowerbed[i] = 1
                n -= 1

        # for length - 1
        if flowerbed[length - 1] == 0 and (
            length == 1 or (length > 1 and flowerbed[length - 2] == 0)
        ):
            n -= 1

        return n <= 0
