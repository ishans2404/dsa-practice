class Graph:
    def __init__(self, val):
        self.V = val
        self.children = defaultdict(list)

    def addEdge(self, u, v):
        self.children[u].append(v)

    def isCyclic(self):
        visited = set()
        recStack = set()

        def dfs(u):
            if u in recStack:
                return True
            if u in visited:
                return False
            
            recStack.add(u)
            for v in self.children[u]:
                if dfs(v):
                    return True
            
            recStack.remove(u)
            visited.add(u)
            return False
    
        for i in range(self.V):
            if i not in visited:
                if dfs(i):
                    return True
        return False

class Solution:
    def canFinish(self, num: int, pre: List[List[int]]) -> bool:
        g = Graph(num)
        for v, u in pre:
            g.addEdge(u, v)
        return not g.isCyclic()
