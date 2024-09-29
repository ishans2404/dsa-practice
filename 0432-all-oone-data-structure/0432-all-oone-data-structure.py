class Node:
    def __init__(self, freq):
        self.next = None
        self.prev = None
        self.freq = freq
        self.keys = set()

class AllOne:
    def __init__(self):
        # dubly linked list of nodes
        self.head = Node(0)
        self.tail = Node(0)
        self.head.next = self.tail
        self.tail.prev = self.head
        # dictionary of string: node
        self.map = {}

    def inc(self, key: str) -> None:
        curr = self.head
        newFreq = 1
        if key in self.map:
            curr = self.map[key]
            newFreq = curr.freq + 1
            curr.keys.remove(key)

        if curr.next.freq == newFreq:
            curr.next.keys.add(key)
        else:
            node = Node(newFreq)
            node.keys.add(key)
            nextNode = curr.next
            node.next = nextNode
            nextNode.prev = node
            curr.next = node
            node.prev = curr

        self.map[key] = curr.next
        if len(curr.keys) == 0 and curr != self.head:
            self.removeNode(curr)

    def dec(self, key: str) -> None:
        curr = self.map[key]
        newFreq = curr.freq - 1
        curr.keys.remove(key)
        if newFreq == 0:
            if len(curr.keys) == 0:
                self.removeNode(curr)
            del self.map[key]
            return

        if curr.prev.freq == newFreq:
            curr.prev.keys.add(key)
        else:
            node = Node(newFreq)
            node.keys.add(key)
            prevNode = curr.prev
            prevNode.next = node
            node.prev = prevNode
            curr.prev = node
            node.next = curr

        self.map[key] = curr.prev
        if len(curr.keys) == 0 and curr != self.head:
            self.removeNode(curr)

    def getMaxKey(self) -> str:
        if self.tail.prev == self.head:
            return ""
        return next(iter(self.tail.prev.keys))

    def getMinKey(self) -> str:
        if self.head.next == self.tail:
            return ""
        return next(iter(self.head.next.keys))

    def removeNode(self, curr: Node) -> None:
        nextNode = curr.next
        prevNode = curr.prev
        prevNode.next = nextNode
        nextNode.prev = prevNode
        curr.next = None
        curr.prev = None


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()