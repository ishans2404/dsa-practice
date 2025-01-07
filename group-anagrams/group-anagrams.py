class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        freq_dict = {}
        for w in strs:
            freq = [0] * 26
            for c in w:
                freq[ord(c) - ord('a')] += 1
            key = ""
            for i in range(26):
                if freq[i] > 0:
                    key += chr(ord('a') + i)
                    key += str(freq[i])
            if key not in freq_dict:
                freq_dict[key] = [w]
            else:
                freq_dict[key].append(w)
        return list(freq_dict.values())