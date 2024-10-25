class Trie:
    def __init__(self):
        self.children = {} # str -> Trie
        self.endf = False # end of folder

    def add(self, path):
        curr = self
        for f in path.split('/'):
            if f not in curr.children:
                curr.children[f] = Trie()
            curr = curr.children[f]
        curr.endf = True

    def prefix_search(self, path):
        curr = self
        fs = path.split('/')
        for i in range(len(fs) - 1):
            curr = curr.children[fs[i]]
            if curr.endf:
                return True
        return False

class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        trie = Trie()
        res = []
        for f in folder:
            trie.add(f)
        for f in folder:
            if not trie.prefix_search(f):
                res.append(f)
        return res