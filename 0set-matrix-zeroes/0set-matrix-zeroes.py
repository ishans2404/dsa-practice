class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix), len(matrix[0])
        def set_zero(i, j):
            for k in range(n):
                matrix[i][k] = 0
            for k in range(m):
                matrix[k][j] = 0
        places = []
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    places.append((i, j))
        for i, j in places:
            set_zero(i, j)
            