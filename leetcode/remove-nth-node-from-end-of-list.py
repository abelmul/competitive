from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        head = ListNode(0, head)

        placeholder = head
        seeker = placeholder.next

        while seeker != None:

            if n != 0:
                seeker = seeker.next
                n -= 1
            else:
                placeholder = placeholder.next
                seeker = seeker.next

        placeholder.next = placeholder.next.next if placeholder.next else None

        return head.next
