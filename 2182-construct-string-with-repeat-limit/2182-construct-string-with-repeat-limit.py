from heapq import heapify, heappush, heappop
class Solution:
    def repeatLimitedString(self, s: str, lim: int) -> str:
        count = Counter(s)
        pq = [(-ord(c), cnt) for c, cnt in count.items()]
        heapify(pq)
        res = []

        while pq:
            char, cnt = heappop(pq)
            char = chr(-char)
            curr = min(cnt, lim)
            for _ in range(curr):
                res.append(char)
            
            if cnt - curr > 0 and pq:
                nxt_char, nxt_cnt = heappop(pq)
                nxt_char = chr(-nxt_char)
                res.append(nxt_char)
                if nxt_cnt > 1:
                    heappush(pq, (-ord(nxt_char), nxt_cnt - 1))
                heappush(pq, (-ord(char), cnt - curr))


        return "".join(res)