from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # floyd's cycle detection
        rabbit = head
        tortoise = head

        while rabbit and rabbit.next and rabbit.next.next:
            tortoise = tortoise.next
            rabbit = rabbit.next.next

            if tortoise == rabbit:
                break

        # cycle
        if rabbit and rabbit.next and rabbit.next.next:
            tortoise = head

            while tortoise != rabbit:
                tortoise = tortoise.next
                rabbit = rabbit.next

            return tortoise

        return None
