class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        return sorted(list(range(1, n+1)), key=lambda x:str(x))

with open("user.out", "w") as f:
    inputs = map(loads, stdin)
    for nums in inputs:
        print(str(Solution().lexicalOrder(nums)).replace(" ", ""), file=f)
exit(0)