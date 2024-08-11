class Solution:
    def finalPositionOfSnake(self, n: int, commands: List[str]) -> int:
        dirs = {"UP":(-1, 0), "RIGHT":(0, 1), "DOWN":(1, 0), "LEFT":(0, -1)}

        x, y = 0, 0
        for i in commands:
            dx, dy = dirs[i]
            x, y = x+dx, y+dy

        return x*n + y