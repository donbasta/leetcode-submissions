using ll = long long;

class Bank {
public:
    int n;
    vector<ll> ve;
    Bank(vector<long long>& balance) : n(balance.size()), ve(balance) {
        
    }
    
    bool transfer(int account1, int account2, long long money) {    
        if (account1 <= 0 || account1 > n) return false;
        if (account2 <= 0 || account2 > n) return false;
        if (ve[account1 - 1] < money) return false;
        ve[account1 - 1] -= money;
        ve[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account <= 0 || account > n) return false;
        ve[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account <= 0 || account > n) return false;
        if (ve[account - 1] < money) return false;
        ve[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */