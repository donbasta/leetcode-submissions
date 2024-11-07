import sys

class Solution:
    def abbreviateProduct(self, left: int, right: int) -> str:
        sys.set_int_max_str_digits(50000)
        prod = 1
        pw = 0
        for j in range(left, right + 1):
            prod *= j
            while (prod % 10 == 0):
                prod //= 10
                pw += 1
        st_prod = str(prod)
        if len(st_prod) <= 10:
            int_part = st_prod
        else:
            int_part = st_prod[:5] + "..." + st_prod[-5:]
        return int_part + f"e{pw}"