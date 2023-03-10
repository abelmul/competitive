from typing import List


class Solution:
    def minOperations(self, logs: List[str]) -> int:
        """
        ["d1/","d2/","../","d21/","./"]
        d1/d21

        """
        folders = []

        for l in logs:
            if l[:-1] == "..":
                if len(folders) > 0:
                    folders.pop()
            elif l[:-1] != ".":
                folders.append(l[:-1])

        return len(folders)
