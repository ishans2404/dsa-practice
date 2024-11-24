class Solution:
  def maxMatrixSum(self, M: List[List[int]]) -> int:
    total, neg, mn = 0, 0, inf
    for row in M:
      for el in row:
        if el < 0:
          el *= -1
          neg ^= 1
        total += el
        if el < mn:
          mn = el
    return total - 2 * neg * mn