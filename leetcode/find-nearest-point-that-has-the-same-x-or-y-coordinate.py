from typing import List

def get_distance(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:

        current_pt = [x, y]
        min_distance = float('inf')
        result = -1

        for i in range(0, len(points)):
            if points[i][0] == x or points[i][1] == y:
                distance = get_distance(current_pt, points[i])

                if distance < min_distance:
                    min_distance = distance
                    result = i

        return result
