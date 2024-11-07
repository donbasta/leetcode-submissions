class Solution:
    def waysToReachStair(self, k: int) -> int:
        k -= 1
        ans = 0
        for j in range(35):
            tot = (1 << j) - 1
            if tot - j - 1 <= k <= tot:
                ans += math.comb(j + 1, tot - k)
        return ans