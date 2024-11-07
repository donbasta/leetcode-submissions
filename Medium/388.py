class Solution:
    def lengthLongestPath(self, input: str) -> int:
        lines = input.split('\n')
        ans = 0
        tmp = []

        def is_file(f):
            for c in f:
                if c == '.':
                    return True
            return False

        for l in lines:
            prf = 0
            while l[prf] == '\t':
                prf += 1
            cur_name = l[prf:]

            if prf < len(tmp):
                while len(tmp) > prf:
                    tmp.pop()

            if is_file(cur_name):
                tmp.append(cur_name)
                ans = max(ans, len("/".join(tmp)))
                # print("/".join(tmp))
                tmp.pop()
            else:
                tmp.append(cur_name)

        return ans