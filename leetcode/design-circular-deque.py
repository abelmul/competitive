class MyCircularDeque:
    def __init__(self, k: int):
        self.queue = [0] * k
        self.head = self.tail = self.size = 0
        self.capacity = k

    def insertFront(self, value: int) -> bool:
        if not self.isFull():
            self.head = (self.head - 1) % self.capacity
            self.queue[self.head] = value
            self.size += 1
            return True

        return False

    def insertLast(self, value: int) -> bool:
        if not self.isFull():
            self.queue[self.tail] = value
            self.tail = (self.tail + 1) % self.capacity
            self.size += 1
            return True

        return False

    def deleteFront(self) -> bool:
        if not self.isEmpty():
            self.head = (self.head + 1) % self.capacity
            self.size -= 1

            return True

        return False

    def deleteLast(self) -> bool:
        if not self.isEmpty():
            self.tail = (self.tail - 1) % self.capacity
            self.size -= 1

            return True
        return False

    def getFront(self) -> int:
        return self.queue[self.head] if not self.isEmpty() else -1

    def getRear(self) -> int:
        return self.queue[self.tail - 1] if not self.isEmpty() else -1

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.capacity


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
