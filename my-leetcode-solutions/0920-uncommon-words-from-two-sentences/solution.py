class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        words = s1.split() + s2.split()
        count = Counter(words)

        result = []

        for word in count:
            if count[word] == 1:
                result.append(word)

        return result
