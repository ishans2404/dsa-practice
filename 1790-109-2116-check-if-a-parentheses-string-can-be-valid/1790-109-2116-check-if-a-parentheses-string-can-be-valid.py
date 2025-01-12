class Solution:
    def canBeValid(self, s: str, l: str) -> bool:
        locked, unlocked = [], []
        for i in range(len(s)):
            if l[i] == '0':
                unlocked.append(i)
            elif s[i] == '(':
                locked.append(i)
            else:
                if locked:
                    locked.pop()
                elif unlocked:
                    unlocked.pop()
                else:
                    return False
        while locked and unlocked and locked[-1] < unlocked[-1]:
            locked.pop()
            unlocked.pop()
        if locked:
            return False
        return True if len(unlocked) % 2 == 0 else False