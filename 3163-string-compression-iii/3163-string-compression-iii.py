class Solution:
    def compressedString(self, w: str) -> str:
        # comp = []
        # prev = w[0]
        # n = len(w)
        # i, j = 0, 0
        # while i < n:
        #     c = w[i]
        #     while j < n and w[j] == c:
        #         j += 1
        #     cnt = j - i
        #     if cnt > 9:
        #         for i in range(cnt // 9):
        #             comp.append("9" + c)
        #     comp.append(str(cnt % 9) + c)
        #     i = j
        # return ''.join(comp)

        comp = []
        def add(num, char):
            for i in range(num // 9):
                comp.append("9" + char)
            if num % 9 != 0:
                comp.append(str(num % 9) + char)

        i, j, n = 0, 0, len(w)

        while i < n:
            while j < n and w[j] == w[i]:
                j += 1
            num = j - i
            if num <= 9:
                comp.append(str(num) + w[i])
            else:
                add(num, w[i])
            i = j

        return ''.join(comp)
