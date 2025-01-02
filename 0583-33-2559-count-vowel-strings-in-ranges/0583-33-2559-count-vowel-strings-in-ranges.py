class Solution:
    def isVowel(self, c):
        return c in {'a', 'e', 'i', 'o', 'u'}
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        n = len(words)
        for i in range(n):
            words[i] = 1 if self.isVowel(words[i][0]) and self.isVowel(words[i][-1]) else 0
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] += words[i] + prefix[i]
        n = len(queries)
        for i in range(n):
            queries[i] = prefix[queries[i][-1] + 1] - prefix[queries[i][0]]
        return queries