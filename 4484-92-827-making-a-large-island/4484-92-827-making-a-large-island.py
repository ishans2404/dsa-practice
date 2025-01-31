class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
    #Initialization
        n=len(grid)
        islandsize={}
        islandid=2
    #use the dfs of the each island size and mark it id
        def dfs(r, c ,id):
            if r<0 or c<0 or r>=n or c>=n or grid[r][c]!=1:
                return 0
            grid[r][c]=id
            size=1
            size+=dfs(r-1,c,id)
            size+=dfs(r+1,c,id)
            size+=dfs(r,c+1,id)
            size+=dfs(r,c-1,id)
            return size
        #assign id and calculate the size
        for r in range(n):
            for c in range(n):
                if grid[r][c]==1:
                    islandsize[islandid]=dfs(r,c,islandid)
                    islandid+=1
        maxsize=max(islandsize.values(),default=0)
       #checking the maximum possibilities
        for r in range(n):
            for c in range(n):
                if grid[r][c]==0:
                    nei=set()
                    for dr,dc in [(1,0),(0,1),(-1,0),(0,-1)]:
                        nr,nc=dr+r,dc+c
                        if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] > 1:
                            nei.add(grid[nr][nc])
                    total=1
        #calculate the potential size of the island 
                    for ni in nei:
                        total+=islandsize[ni]
                    maxsize=max(maxsize,total)
        return maxsize