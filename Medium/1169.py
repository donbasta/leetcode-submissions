class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        T = list(map(lambda x: x.split(","), transactions))
        ret = []
        for i in range(len(T)):
            if int(T[i][2]) > 1000:
                ret.append(",".join(T[i]))
                continue
            cant = False
            for j in range(len(T)):
                if i == j:
                    continue
                if T[i][0] == T[j][0] and T[i][3] != T[j][3] and abs(int(T[i][1]) - int(T[j][1])) <= 60:
                    cant = True
                    break
            if cant:
                ret.append(",".join(T[i]))
        return ret
                

        