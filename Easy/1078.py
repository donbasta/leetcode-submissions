class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        tokens = text.split()
        if (len(tokens) < 3):
            return []
        thirds = []
        for i in range(len(tokens) - 2):
            if tokens[i] == first and tokens[i + 1] == second:
                thirds.append(tokens[i + 2])
        return thirds