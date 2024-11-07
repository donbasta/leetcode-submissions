class Solution:
    B = 60
    
    def fpow(self, a, b, mod):
        ret = 1
        while b > 0:
            if b % 2 == 1:
                ret = (ret * a) % mod
            a = (a * a) % mod
            b //= 2
        return ret
    
    def F(self, x):
        ret = 0
        for i in range(self.B):
            byk = x // (1 << (i + 1))
            tmp = byk * (1 << i)
            if (x % (1 << (i + 1)) >= (1 << i)):
                tmp += (x % (1 << (i + 1))) - (1 << i) + 1
            ret += tmp
        return ret
    
    def G(self, x):
        ret = 0
        for i in range(self.B):
            byk = x // (1 << (i + 1))
            tmp = byk * (1 << i)
            if (x % (1 << (i + 1)) >= (1 << i)):
                tmp += (x % (1 << (i + 1))) - (1 << i) + 1
            ret += tmp * i
        return ret
    
    def findProductsOfElements(self, queries: List[List[int]]) -> List[int]:
        ans = []
        MX = 10 ** 16
        for q in queries:
            mod = q[2]
            if mod == 1:
                ans.append(0)
                continue
            
            fr = q[0]
            to = q[1]
            
            lo = 0
            hi = MX
            while lo <= hi:
                mid = (lo + hi) // 2
                if self.F(mid) > fr:
                    hi = mid - 1
                else:
                    L = mid
                    lo = mid + 1
            
            lo = 0
            hi = MX
            while lo <= hi:
                mid = (lo + hi) // 2
                if self.F(mid) >= to + 1:
                    R = mid
                    hi = mid - 1
                else:
                    lo = mid + 1
            
            tot = self.G(R) - self.G(L)
            bitL = []
            bitR = []
            for i in range(self.B):
                if ((L + 1) >> i) & 1:
                    bitL.append(i)
                if (R >> i) & 1:
                    bitR.append(i)
            
            l1 = self.F(L)
            for j in range(l1, fr):
                tot -= bitL[j - l1]
            
            r2 = self.F(R)
            for j in range(r2 - 1, to, -1):
                tot -= bitR[len(bitR) - r2 + j]
            
            ans.append(self.fpow(2, tot, mod))
        return ans
        