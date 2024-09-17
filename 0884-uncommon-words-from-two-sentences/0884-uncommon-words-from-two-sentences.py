from collections import Counter
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        a = list(map(str, s1.split(' ')))
        b = list(map(str, s2.split(' ')))
        dic = Counter(a + b)
        a = []
        for elem in dic.keys():
            if dic[elem] == 1:
                a.append(elem)
        return a