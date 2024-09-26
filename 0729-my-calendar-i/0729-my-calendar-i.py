class BST:
    def __init__(self, start, end):
        self.left = None
        self.right = None
        self.start = start
        self.end = end

    def insert(self, start, end):
        curr = self
        while True:
            if end <= curr.start:
                if not curr.left:
                    curr.left = BST(start, end)
                    return True
                curr = curr.left
            elif curr.end <= start:
                if not curr.right:
                    curr.right = BST(start, end)
                    return True
                curr = curr.right
            else:
                return False

class MyCalendar:
    def __init__(self):
        self.root = None        

    def book(self, start: int, end: int) -> bool:
        if not self.root:
            self.root = BST(start, end)
            return True
        return self.root.insert(start, end)


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)