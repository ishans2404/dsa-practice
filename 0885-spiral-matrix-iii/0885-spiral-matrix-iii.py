class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        i = rStart
        j = cStart
        cRow, cCol = 0, 0
        row, col = 1, 1
        required = rows * cols

        res = [[i, j]]

        while len(res) < required:
            while  cCol < col:
                j += 1
                if j > -1 and j < cols and i > -1 and i < rows:
                    res.append([i, j])
                cCol += 1

            if len(res) >= required: break
            
            while cRow < row:
                i += 1
                if j > -1 and j < cols and i > -1 and i < rows:
                    res.append([i, j])
                cRow += 1

            if len(res) >= required: break
            
            cRow, cCol = 0, 0
            row += 1
            col += 1

            while cCol < col:
                j -= 1
                if j > -1 and j < cols and i > -1 and i < rows:
                    res.append([i, j])
                cCol += 1

            if len(res) >= required: break
            
            while cRow < row:
                i -= 1
                if j > -1 and j < cols and i > -1 and i < rows:
                    res.append([i, j])
                cRow += 1

            if len(res) >= required: break

            cRow, cCol = 0, 0
            row += 1
            col += 1
        
        return res