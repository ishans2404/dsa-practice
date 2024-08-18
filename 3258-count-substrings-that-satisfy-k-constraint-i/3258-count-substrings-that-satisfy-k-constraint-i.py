class Solution:
    def countKConstraintSubstrings(self, s: str, p: int) -> int:
        cnt = 0
        for i in range(len(s)):
            z, o = 0, 0
            for j in range(i, len(s)):
                
                if s[j] == '0':
                    z += 1
                else:
                    o += 1
                
                if p >= z or p >= o:
                    cnt += 1
                else:
                    break
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