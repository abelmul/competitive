class Node:
    def __init__(self, value, next):
        self.value = value
        self.next = next

    def __repr__(self):
        return f"Node({self.value}, {self.next if self.next else 'None'})"


class MyLinkedList:
    def __init__(self):
        self.head = Node(0, None)
        self.size = 0

    def get(self, index: int) -> int:
        if index >= self.size:
            return -1

        ptr = self.head.next
        while index != 0:
            ptr = ptr.next
            index -= 1

        return ptr.value

    def addAtHead(self, val: int) -> None:
        self.head.next = Node(val, self.head.next)
        self.size += 1

        # print("addAtHead")
        # print(self.head)

    def addAtTail(self, val: int) -> None:
        ptr = self.head

        while ptr.next:
            ptr = ptr.next

        ptr.next = Node(val, None)
        self.size += 1

        # print("addAtTail")
        # print(self.head)

    def addAtIndex(self, index: int, val: int) -> None:
        if index == 0:
            self.addAtHead(val)
        elif index == self.size:
            self.addAtTail(val)
        elif index < self.size:
            prev = self.head
            ptr = self.head.next

            while index != 0:
                prev = ptr
                ptr = ptr.next
                index -= 1

            prev.next = Node(val, ptr)
            self.size += 1

        # print("addAtIndex")
        # print(self.head)

    def deleteAtIndex(self, index: int) -> None:
        if index < self.size:
            prev = self.head
            ptr = self.head.next

            while index != 0:
                prev = ptr
                ptr = ptr.next
                index -= 1

            prev.next = ptr.next
            self.size -= 1

        # print("deleteAtIndex")
        # print(self.head)


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
