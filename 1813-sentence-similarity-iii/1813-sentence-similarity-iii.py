class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        s1 = sentence1.split()
        s2 = sentence2.split()
        if len(s2) > len(s1):
            s1, s2 = s2, s1
        n, m = len(s1), len(s2)
        pre = 0
        suf = 0
        while pre < n and pre < m:
            if s1[pre] != s2[pre]:
                break
            pre += 1
        while suf < n and suf < m:
            if s1[n - 1 - suf] != s2[m - 1 - suf]:
                break
            suf += 1
        return suf + pre > m - 1

def newmain():
    input_data = sys.stdin.read().strip()
    lines = input_data.splitlines()
    
    num_test_cases = len(lines) // 2
    results = []

    for i in range(num_test_cases):
        s1 = json.loads(lines[2*i])
        s2 = json.loads(lines[2*i+1])
        result = Solution().areSentencesSimilar(s1, s2)
        results.append(json.dumps(result, separators=(',', ':')))

    with open('user.out', 'w') as f:
        for result in results:
            f.write(f"{result}\n")

if __name__ == "__main__":
    newmain()
    exit(0)