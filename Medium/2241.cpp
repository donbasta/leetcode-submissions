class ATM {
public:
    vector<long long> cnt;
    vector<long long> notes;

    ATM() {
        cnt.resize(5);
        notes = {20, 50, 100, 200, 500};        
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            cnt[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> used(5);
        for (int i = 4;i >= 0; i--) {
            long long lmao = notes[i] * min(cnt[i], (amount / notes[i]));
            used[i] = min(cnt[i], (amount / notes[i]));
            amount -= lmao;
        }
        if (amount != 0) return {-1};
        for (int i = 0; i < 5; i++) {
            cnt[i] -= used[i];
        }
        return used;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */