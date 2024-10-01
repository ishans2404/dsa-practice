class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        rems = [0] * k
        for elem in arr:
            rem = ((elem % k) + k) % k
            rems[rem] += 1
        if rems[0] % 2 == 1:
            return False
        for rem in range(1, (k // 2) + 1):
            if rems[rem] != rems[k - rem]:
                return False
        return True

def newmain():
    input_data = sys.stdin.read().strip()
    lines = input_data.splitlines()
    
    num_test_cases = len(lines) // 2
    results = []

    for i in range(num_test_cases):
        arr, k = json.loads(lines[2*i]), json.loads(lines[2*i+1])
        result = Solution().canArrange(arr, k)
        results.append(json.dumps(result))

    with open('user.out', 'w') as f:
        for result in results:
            f.write(f"{result}\n")

if __name__ == "__main__":
    newmain()
    exit(0)