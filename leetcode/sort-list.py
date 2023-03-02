from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def merge(
        self, dummy: ListNode, list1: Optional[ListNode], list2: Optional[ListNode]
    ):
        ptr = dummy

        while list1 or list2:
            if list1 and list2:
                if list1.val < list2.val:
                    ptr.next = list1
                    list1 = list1.next
                else:
                    ptr.next = list2
                    list2 = list2.next
            elif list1:
                ptr.next = list1
                list1 = list1.next
            else:
                ptr.next = list2
                list2 = list2.next

            ptr = ptr.next

        ptr.next = None

    def cutListInHalf(self, dummy: ListNode) -> Optional[ListNode]:
        prev_ptr = None
        slow_ptr = dummy.next
        fast_ptr = dummy
        while fast_ptr.next and fast_ptr.next.next:
            prev_ptr = slow_ptr
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next.next
        if prev_ptr:
            prev_ptr.next = None
        return slow_ptr

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # merge sort
        if not head:
            return head

        dummy = ListNode(0, head)
        second_half = self.cutListInHalf(dummy)

        if second_half and dummy.next != second_half:
            list1 = self.sortList(dummy.next)
            list2 = self.sortList(second_half)

            self.merge(dummy, list1, list2)

        return dummy.next
