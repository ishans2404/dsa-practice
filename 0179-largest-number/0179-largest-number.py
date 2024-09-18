class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = list(map(str, nums))
        nums.sort(key=lambda x: x * 10, reverse=True)
        if nums[0] == '0':
            return '0'
        return ''.join(nums)
def kdsmain():
    input_text = sys.stdin.read().strip()
    test_cases = input_text.splitlines()
    
    test_case_count = len(test_cases)
    output_results = []

    solver = Solution()
    for i in range(test_case_count):
        input_string = json.loads(test_cases[i])
        result = solver.largestNumber(input_string)
        output_results.append(str(result))

    with open('user.out', 'w') as output_file:
        for result in output_results:
            output_file.write(f"\"{result}\"\n")

if __name__ == "__main__":
    kdsmain()
    exit(0)