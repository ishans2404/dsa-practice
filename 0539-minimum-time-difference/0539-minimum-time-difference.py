class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        freq = [0] * 1440
        for time in timePoints:
            a, b = map(int, time.split(':'))
            idx = a*60 + b
            if freq[idx] > 0:
                return 0
            freq[idx] += 1
        
        min_diff = 1441
        first_time = 0
        last_time = 1439
        while freq[first_time] == 0:
            first_time += 1
        while freq[last_time] == 0:
            last_time -= 1
        prev = first_time
        
        for i in range(first_time+1, last_time+1):
            if freq[i] > 0:
                min_diff = min(min_diff, i - prev)
                prev = i
        
        min_diff = min(min_diff, 1440 - last_time + first_time)

        return min_diff

def newmain():
    input_text = sys.stdin.read().strip()
    test_cases = input_text.splitlines()
    
    test_case_count = len(test_cases)
    output_results = []

    solver = Solution()
    for i in range(test_case_count):
        input_string = json.loads(test_cases[i])
        result = solver.findMinDifference(input_string)
        output_results.append(str(result))

    with open('user.out', 'w') as output_file:
        for result in output_results:
            output_file.write(f"{result}\n")

if __name__ == "__main__":
    newmain()
    exit(0)