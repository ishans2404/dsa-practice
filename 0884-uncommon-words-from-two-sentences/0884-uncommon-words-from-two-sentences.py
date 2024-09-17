
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        count1 = Counter(s1.split())
        count2 = Counter(s2.split())
        set1 = [w1 for w1 in count1.keys() if count1[w1] <= 1 and count2[w1] <= 1]
        set2 = [w2 for w2 in count2.keys() if count1[w2] <= 1 and count2[w2] <= 1]

        return list(set(set1) - set(set2)) + list(set(set2) - set(set1))

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