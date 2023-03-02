# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        number = 0

        ptr = head

        while ptr:
            number = number << 1 | ptr.val

            ptr = ptr.next

        return number
