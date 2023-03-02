from typing import List


class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        rows, columns = len(box), len(box[0])

        for r in range(rows):
            placeholder = columns - 1
            seeker = columns - 2

            while seeker >= 0:
                if box[r][placeholder] != ".":
                    placeholder -= 1
                elif box[r][seeker] == "*":
                    placeholder = seeker
                elif box[r][seeker] == "#":
                    box[r][placeholder] = box[r][seeker]
                    box[r][seeker] = "."
                    placeholder -= 1

                seeker -= 1

        # rotate 90 degrees
        return [reversed([box[j][i] for j in range(rows)]) for i in range(columns)]
