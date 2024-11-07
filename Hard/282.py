class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        ret = []
        n = len(num)
        
        def rec(idx, cur_exp):
            cur_exp += num[idx]
            if idx == n - 1:
                if eval(cur_exp) == target:
                    ret.append(cur_exp)
                return
            for op in ['', '+', '-', '*']:
                if op == '' and cur_exp[-1] == '0' and ((len(cur_exp) >= 2 and cur_exp[-2] in ['+', '-', '*']) or len(cur_exp) == 1):
                    continue
                cur_exp += op
                rec(idx + 1, cur_exp)
                if op != '':
                    cur_exp = cur_exp[:-1]

        buf = ""
        rec(0, buf)
        return ret
        