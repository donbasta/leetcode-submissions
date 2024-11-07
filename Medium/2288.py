class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        tokens = sentence.split()

        import re
        pattern = r"^\$\d+$"
        for i in range(len(tokens)):
            if re.match(pattern, tokens[i]):
                price = int(tokens[i][1:])
                new_price = price * (100 - discount) / 100
                new_tok = f"${new_price:.2f}"
                tokens[i] = new_tok
        
        return " ".join(tokens)