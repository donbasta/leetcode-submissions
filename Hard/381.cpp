#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;

class RandomizedCollection {
public:
    unordered_map<int, int> cnt;
    oset cont;
    RandomizedCollection() {
    
    }
    
    bool insert(int val) {
        bool ret = true;
        if (cnt[val] > 0) ret = false;
        cnt[val]++;
        cont.insert(make_pair(val, cnt[val]));
        return ret;
    }
    
    bool remove(int val) {
        if (!cnt.count(val)) return false;
        cont.erase(make_pair(val, cnt[val]));
        cnt[val]--;
        if (cnt[val] == 0) cnt.erase(val);
        return true;
    }
    
    int getRandom() {
        int sz = cont.size();
        int pick = rand() % sz;
        return cont.find_by_order(pick)->first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */