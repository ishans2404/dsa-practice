class Solution:
    def countGoodNodes(self, edges):
        from collections import defaultdict
        
        # build the tree using an adjacency list
        n = len(edges) + 1  # Number of nodes
        tree = defaultdict(list)
        for a, b in edges:
            tree[a].append(b)
            tree[b].append(a)
        
        # Step 2: Perform DFS to calculate subtree sizes
        subtree_size = [0] * n
        
        def dfs(node, parent):
            size = 1  # Start with the node itself
            for child in tree[node]:
                if child != parent:
                    size += dfs(child, node)
            subtree_size[node] = size
            return size
        
        dfs(0, -1)  # Start DFS from the root node 0
        
        # Step 3: Count good nodes
        good_nodes_count = 0
        
        def is_good_node(node, parent):
            child_sizes = set()
            for child in tree[node]:
                if child != parent:
                    child_sizes.add(subtree_size[child])
            
            # Node is good if all child subtree sizes are the same
            if len(child_sizes) <= 1:
                nonlocal good_nodes_count
                good_nodes_count += 1
            
            for child in tree[node]:
                if child != parent:
                    is_good_node(child, node)
        
        is_good_node(0, -1)  # Start checking from the root node 0
        
        return good_nodes_count
