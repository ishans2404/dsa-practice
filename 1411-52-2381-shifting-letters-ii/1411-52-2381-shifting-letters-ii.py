class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        arr = [0] * (n + 1)
        for start, end, dirkn in shifts:
            if dirkn == 0:
                dirkn = -1
            arr[start] += dirkn
            if end + 1 < n:
                arr[end + 1] -= dirkn
        for i in range(1, n):
            arr[i] += arr[i - 1]
        res = [None] * n
        for i in range(n):
            shift = arr[i] % 26
            new_char = chr((ord(s[i]) - 97 + shift) % 26 + 97)
            res[i] = new_char
        return ''.join(res)