class Trie:
    def __init__(self):
        self.children = {}

    def add(self, word):
        curr = self
        for w in word:
            if w not in curr.children:
                curr.children[w] = Trie()
            curr = curr.children[w]

    def prefix_search(self, depth=0):
        curr = self
        res = ""
        for d in range(depth):
            count = len(curr.children)
            if count != 1:
                break
            w = next(iter(curr.children))
            res += w
            curr = curr.children[w]
        return res

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        trie = Trie()
        min_len = float('inf')
        for w in strs:
            if not w:
                return ""
            trie.add(w)
            min_len = min(min_len, len(w))
        return trie.prefix_search(min_len)