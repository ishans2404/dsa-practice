class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        res = list(range(1, n+1))
        res.sort(key=lambda a : str(a))
        return res