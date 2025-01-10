class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        words1 = [(w, Counter(w)) for w in words1]
        words2 = [Counter(w) for w in words2]
        new_words2 = {}
        for cnt in words2:
            for key in cnt.keys():
                if key not in new_words2:
                    new_words2[key] = cnt[key]
                else:
                    new_words2[key] = max(new_words2[key], cnt[key])

        def valid(freq1):
            for ch in new_words2.keys():
                if new_words2[ch] > freq1[ch]:
                    return False
            return True

        res = []
        for w, freq1 in words1:
            if valid(freq1):
                res.append(w)
        return res