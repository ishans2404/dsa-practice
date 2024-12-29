class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        MOD = 10**9 + 7

        # (idx, char) : freq among all words
        freq = defaultdict(int)
        for w in words:
            for i, c in enumerate(w):
                freq[(i, c)] += 1
        
        t = len(words[0])
        n = len(target)
        # (i, k) : numWays
        dp = {}

        # i -> idx of target
        # k -> idx of word w
        def dfs(i, k):
            if i == n:
                return 1
            if k == t:
                return 0
            if (i, k) in dp:
                return dp[(i, k)]
            
            c = target[i]
            # skip kth position
            dp[(i, k)] = dfs(i, k + 1)
            dp[(i, k)] += freq[(k, c)] * dfs(i + 1, k + 1)

            return dp[(i, k)] % MOD
        
        return dfs(0, 0)