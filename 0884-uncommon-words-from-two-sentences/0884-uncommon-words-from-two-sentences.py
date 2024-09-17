
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        word_count = Counter(s1.split()) + Counter(s2.split())
        res = [word for word, count in word_count.items() if count == 1]
        return res

def newmain():
    input_text = sys.stdin.read().strip()
    test_cases = input_text.splitlines()
    
    test_case_count = len(test_cases) // 2
    output_results = []

    solver = Solution()
    for i in range(test_case_count):
        s1 = json.loads(test_cases[2*i])
        s2 = json.loads(test_cases[2*i+1])
        result = solver.uncommonFromSentences(s1, s2)
        output_results.append(result)

    with open('user.out', 'w') as output_file:
        for result in output_results:
            output_file.write(f"{json.dumps(result)}\n")

if __name__ == "__main__":
    newmain()
    exit(0)