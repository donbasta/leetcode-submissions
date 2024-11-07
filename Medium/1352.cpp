class ProductOfNumbers {
public:
    int idx = 0, cur = 1;
    vector<int> zero_pos, pref;
    ProductOfNumbers() {
        
    }

    void add(int num) {
        if (num == 0) {
            zero_pos.push_back(idx);
            cur = 1;
        } else {
            cur *= num;
        }
        idx++;
        pref.push_back(cur);
    }
    
    int getProduct(int k) {
        int cur = idx - 1, lst = idx - k;
        int car = lower_bound(zero_pos.begin(), zero_pos.end(), lst) - zero_pos.begin();
        if (car == zero_pos.size()) {
            return pref[cur] / (lst ? pref[lst - 1] : 1);
        }
        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */