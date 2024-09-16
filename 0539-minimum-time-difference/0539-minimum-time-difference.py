class Solution:
    def findMinDifference(self, timePoints):
        cnt = 0
        for time in timePoints:
            a, b = map(int, time.split(':'))
            timePoints[cnt] = a * 60 + b
            cnt += 1
        timePoints.sort()
        res = 1441
        for i in range(1, len(timePoints)):
            res = min(res, timePoints[i] - timePoints[i-1])
        res = min(res, 1440 - timePoints[-1] + timePoints[0])

        return res