class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        mx = 0
        for s in strs:
            try:
                sint = int(s)
                mx = max(mx, sint)
            except ValueError:
                mx = max(mx, len(s))
        return mx