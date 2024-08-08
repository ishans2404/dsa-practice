class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]  # left, down, right, up
        res = []  # store valid pair
        steps = 1
        direction = 0
        r = rStart
        c = cStart
        total = rows * cols
        while len(res) < total:
            for a in range(2):
                rnew, cnew = directions[direction]
                for b in range(steps):
                    if (0 <= r < rows and 0 <= c < cols):
                        res.append([r, c])
                    r += rnew
                    c += cnew
                direction = (direction + 1) % 4
            steps += 1
        return res