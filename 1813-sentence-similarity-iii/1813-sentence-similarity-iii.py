class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        s1 = sentence1.split()
        s2 = sentence2.split()
        if len(s2) > len(s1):
            s1, s2 = s2, s1
        n, m = len(s1), len(s2)
        pre = 0
        suf = 0
        while pre < n and pre < m:
            if s1[pre] != s2[pre]:
                break
            pre += 1
        while suf < n and suf < m:
            if s1[n - 1 - suf] != s2[m - 1 - suf]:
                break
            suf += 1
        return suf + pre > m - 1
