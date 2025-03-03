class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        less, more, equal = [], [], 0
        for i in range(len(nums)):
            if nums[i] < pivot:
                less.append(nums[i])
            elif nums[i] == pivot:
                equal += 1
            elif nums[i] > pivot:
                more.append(nums[i])
        return less + [pivot] * equal + more