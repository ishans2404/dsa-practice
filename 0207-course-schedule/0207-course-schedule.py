class Graph:
    # -1: not processed, 0: processing, 1: processed
    def __init__(self, val):
        self.V = val
        self.children = defaultdict(list)

    def addEdge(self, u, v):
        self.children[u].append(v)

    def dfsutil(self, u, color):
        color[u] = 0
        for v in self.children[u]:
            if color[v] == 0 or (color[v] == -1 and self.dfsutil(v, color)):
                return True
        color[u] = 1
        return False
    
    def isCyclic(self):
        color = [-1] * self.V
        for i in range(self.V):
            if color[i] == -1 and self.dfsutil(i, color):
                return True
        return False

class Solution:
    def canFinish(self, num: int, pre: List[List[int]]) -> bool:
        g = Graph(num)
        for v, u in pre:
            g.addEdge(u, v)
        return not g.isCyclic()