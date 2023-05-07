from typing import List


class Solution:
    def average(self, salary: List[int]) -> float:
        min_salary = float("inf")
        max_salary = 0
        sum_salary = 0

        for i in salary:
            sum_salary += i
            min_salary = min(min_salary, i)
            max_salary = max(max_salary, i)

        return (sum_salary - min_salary - max_salary) / (len(salary) - 2)
