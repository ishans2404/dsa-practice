class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        def numOp(i):
            cnt = 0
            for k in range(n):
                if k != i and boxes[k] == '1':
                    cnt += abs(k - i)
            return cnt
        res = []
        for i in range(n):
            res.append(numOp(i))
        return res