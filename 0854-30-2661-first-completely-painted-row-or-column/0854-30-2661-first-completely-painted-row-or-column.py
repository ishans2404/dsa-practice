class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        lookup = {}
        m, n = len(mat), len(mat[0])
        for r in range(m):
            for c in range(n):
                lookup[mat[r][c]] = (r, c)
        row_fill = [0] * m
        col_fill = [0] * n
        for i in range(len(arr)):
            r, c = lookup[arr[i]]
            row_fill[r] += 1
            col_fill[c] += 1
            if row_fill[r] == n or col_fill[c] == m:
                return i
        return -1