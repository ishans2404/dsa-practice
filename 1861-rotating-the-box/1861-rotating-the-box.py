class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n = len(box), len(box[0])
        grid = [[None] * m for _ in range(n)]
        for row in box:
            curr = n - 1
            for i in range(n - 1, -1, -1):
                if row[i] == "*":
                    curr = i - 1
                elif row[i] == "#":
                    row[i], row[curr] = row[curr], row[i]
                    curr -= 1
        for j in range(n):
            for i in range(m):
                grid[j][i] = box[m - i - 1][j]

        return grid