from collections import defaultdict
from typing import List


class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        duplicates = defaultdict(set)

        for p in paths:
            path = p.split()
            for i in path[1:]:
                data = i.split("(")
                name = data[0]
                content = data[1][:-1]

                duplicates[content].add(path[0] + "/" + name)
        res = []

        for v in duplicates.values():
            if len(v) > 1:
                res.append(v)

        return res
