class Solution:
    def maxPoints(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])

        curRow = grid[0]
        for r in range(1, R):
            nextRow = grid[r]
            left = [0] * C
            right = [0] * C

            left[0] = curRow[0]
            for c in range(1, C):
                left[c] = max(left[c - 1] - 1, curRow[c])
            right[C-1] = curRow[C-1]
            for c in range(C-2, -1, -1):
                right[c] = max(right[c + 1] - 1, curRow[c])
            
            for c in range(C):
                nextRow[c] += max(left[c], right[c])
                
            curRow = nextRow
        
        return max(curRow)
    
def main():
    input = sys.stdin.read().strip()
    

    test_cases = input.splitlines()
    
    results = []
    for case in test_cases:
       
        arrays = json.loads(case)
        results.append(Solution().maxPoints(arrays))
    

    with open('user.out', 'w') as f:
        for result in results:
            f.write(f"{result}\n")

if __name__ == "__main__":
    main()
    exit(0)