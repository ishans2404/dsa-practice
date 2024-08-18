class Solution:
    def maxEnergyBoost(self, energyDrinkA: List[int], energyDrinkB: List[int]) -> int:
        n = len(energyDrinkA)
        dpA, dpB = 0, 0

        for i in range(n):
            newDpA = max(dpA + energyDrinkA[i], dpB)
            newDpB = max(dpB + energyDrinkB[i], dpA)
            dpA, dpB = newDpA, newDpB

        return max(dpA, dpB)
