class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # right, down, left, up
        result = []
        steps = 1
        d = 0
        r, c = rStart, cStart
        
        while True:
            for _ in range(2):  # Two times per layer
                for _ in range(steps):
                    if 0 <= r < rows and 0 <= c < cols:
                        result.append([r, c])
                        if len(result) == rows * cols: return result
                    r += directions[d][0]
                    c += directions[d][1]
                d = (d + 1) % 4
            steps += 1
        
        return result
