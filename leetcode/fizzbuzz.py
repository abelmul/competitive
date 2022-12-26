from typing import List

class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        l  = []
        j = n
        for i in range(j):
            n = i + 1
            if n % 15 == 0:
                l.append("FizzBuzz")
            elif n % 5 == 0:
                l.append("Buzz")
            elif n % 3 == 0:
                l.append("Fizz")
            else:
                l.append(str(n))
        return l
