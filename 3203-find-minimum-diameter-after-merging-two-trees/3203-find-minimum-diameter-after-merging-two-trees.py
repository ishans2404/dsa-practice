class Solution:
    def minimumDiameterAfterMerge(self, edges1: List[List[int]], edges2: List[List[int]]) -> int:
        n = len(edges1) + 1
        m = len(edges2) + 1

        def get_adj(edges):
            adj = defaultdict(list)
            for u, v in edges:
                adj[u].append(v)
                adj[v].append(u)
            return adj
        
        adj1 = get_adj(edges1)
        adj2 = get_adj(edges2)

        def get_diameter(curr, par, adj):
            max_d = 0
            max_child_paths = [0, 0]
            for v in adj[curr]:
                if v == par:
                    continue
                v_d, v_max_leaf_path =  get_diameter(v, curr, adj)
                max_d = max(max_d, v_d)

                heappush(max_child_paths, v_max_leaf_path)
                heappop(max_child_paths)

            max_d = max(max_d, sum(max_child_paths))
            return [max_d, 1 + max(max_child_paths)]

        d1, _ = get_diameter(0, -1, adj1)
        d2, _ = get_diameter(0, -1, adj2)
        return max(d1, d2, 1 + ceil(d1/2) + ceil(d2/2))