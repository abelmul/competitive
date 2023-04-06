from random import randint
from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def __init__(self, head: Optional[ListNode]):
        self.dummy = ListNode(0, head)
        self.size = 0

        while head:
            head = head.next
            self.size += 1

    def getRandom(self) -> int:
        # use python random
        n = randint(1, self.size)

        node = self.dummy
        while n > 0:
            node = node.next
            n -= 1

        return node.val


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
