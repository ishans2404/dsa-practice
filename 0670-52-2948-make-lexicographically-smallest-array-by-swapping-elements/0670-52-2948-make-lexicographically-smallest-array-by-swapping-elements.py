class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        groups = []
        mapping = {}
        for n in sorted(nums):
            if not groups or abs(groups[-1][-1] - n) > limit:
                groups.append(deque())
            groups[-1].append(n)
            mapping[n] = len(groups) - 1
        res = []
        for n in nums:
            elem = groups[mapping[n]].popleft()
            res.append(elem)
        return res