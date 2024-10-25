class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.endf = False

    def add(self, word):
        curr = self
        for w in word:
            idx = ord(w) - ord('a')
            if curr.children[idx] is None:
                curr.children[idx] = Trie()
            curr = curr.children[idx]
        curr.endf = True

    def prefix_search(self, depth=0):
        curr = self
        res = ""
        for d in range(depth):
            count = sum(1 for child in curr.children if child is not None)
            if count != 1:
                break
            for i in range(26):
                if curr.children[i] is not None:
                    res += chr(ord('a') + i)
                    curr = curr.children[i]
                    break
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

def newmain():
    input_data = sys.stdin.read().strip()
    lines = input_data.splitlines()
    
    num_test_cases = len(lines)
    results = []

    for i in range(num_test_cases):
        words = json.loads(lines[i])
        result = Solution().longestCommonPrefix(words)
        results.append(json.dumps(result, separators=(',', ':')))

    with open('user.out', 'w') as f:
        for result in results:
            f.write(f"{result}\n")

if __name__ == "__main__":
    newmain()
    exit(0)