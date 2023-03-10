from typing import List, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        ptr = head

        stack = []
        res = {}
        i = 0

        while ptr:
            while stack and stack[-1][1] < ptr.val:
                j, _ = stack[-1]
                res[j] = ptr.val

                stack.pop()

            stack.append((i, ptr.val))

            ptr = ptr.next
            i += 1

        return [res.get(i, 0) for i in range(i)]
