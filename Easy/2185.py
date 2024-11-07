class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        ans = 0
        for w in words:
            if w.startswith(pref):
                ans += 1
        return ans