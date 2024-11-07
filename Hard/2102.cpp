#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class SORTracker {
public:
    
    int countGet = 0;
    tree<pair<int, string>, null_type, less<pair<int, string>>, rb_tree_tag, tree_order_statistics_node_update> ose;
    
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        ose.insert(make_pair(-score, name));
    }
    
    string get() {
        auto lol = ose.find_by_order(countGet++);
        return lol->second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */