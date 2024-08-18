class Solution:
    def countKConstraintSubstrings(self, s: str, p: int) -> int:
        print(s, p)
        cnt = 0
        for i in range(len(s)):
            for j in range(i, len(s)):
                z, o = 0, 0
                for k in range(i, j+1):
                    if s[k] == '0':
                        z += 1
                    else:
                        o += 1
                cnt += 1
                if p < z and p < o:
                    cnt -= 1
        return cnt
        
def main():
    input = sys.stdin.read().strip()
    test_cases = input.splitlines()
    results = []
    for i in range(0, len(test_cases), 2):
        s = test_cases[i]
        s = s[1:-1]
        p = int(test_cases[i+1])
        results.append(Solution().countKConstraintSubstrings(s, p))
    
    with open('user.out', 'w') as f:
        for result in results:
            f.write(f"{result}\n")

if __name__ == "__main__":
    main()
    exit(0)