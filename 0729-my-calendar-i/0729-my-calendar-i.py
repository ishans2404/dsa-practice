import bisect

class MyCalendar:
    def __init__(self):
        self.intervals = []

    def book(self, start: int, end: int) -> bool:
        pos = bisect.bisect_left(self.intervals, (start, end))  # position for new interval
        
        # check overlap
        if pos > 0 and self.intervals[pos - 1][1] > start:
            return False
        if pos < len(self.intervals) and self.intervals[pos][0] < end:
            return False
        
        # insert
        self.intervals.insert(pos, (start, end))
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)