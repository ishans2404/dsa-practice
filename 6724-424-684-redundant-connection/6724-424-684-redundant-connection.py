class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n + 1))  # Initialize each node as its own parent

    def find(self, u):
        if self.parent[u] == u:
            return u
        self.parent[u] = self.find(self.parent[u])  # Path compression
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            self.parent[root_v] = root_u  # Merge sets
            return True
        return False  # redundant edge detected

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)  # Number of nodes (since n edges for n nodes)
        ds = DisjointSet(n)
        for u, v in edges:
            if not ds.union(u, v):
                return [u, v]  # Return the first redundant edge
        return []        