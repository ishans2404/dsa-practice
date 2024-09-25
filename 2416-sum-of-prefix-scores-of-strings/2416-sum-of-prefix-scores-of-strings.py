class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        prefix_count = defaultdict(int)
        for word in words:
            for i in range(len(word)):
                prefix_count[word[:i+1]] += 1
        res = []
        for word in words:
            score = 0
            for i in range(len(word)):
                score += prefix_count[word[:i + 1]]
            res.append(score)
        
        return res

def newmain():
    input_data = sys.stdin.read().strip()
    lines = input_data.splitlines()
    
    num_test_cases = len(lines)
    results = []

    for i in range(num_test_cases):
        words = json.loads(lines[i])
        result = Solution().sumPrefixScores(words)
        results.append(json.dumps(result, separators=(',', ':')))

    with open('user.out', 'w') as f:
        for result in results:
            f.write(f"{result}\n")

if __name__ == "__main__":
    newmain()
    exit(0)