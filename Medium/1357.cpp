class Cashier {
public:
    int n, discount;
    unordered_map<int, int> id_to_price;
    int cur = 0;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) : n(n), discount(discount) {
        for (int i = 0; i < products.size(); i++) {
            id_to_price[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        long long tot = 0;
        for (int i = 0; i < product.size(); i++) {
            tot += 1ll * id_to_price[product[i]] * amount[i];
        }
        cur++;
        double ret = tot;
        if (cur % n == 0) {
            ret = ret * (100 - discount) / 100.0;
        }
        return ret;
    }

};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */