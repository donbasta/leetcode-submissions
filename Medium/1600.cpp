class ThroneInheritance {
public:
    unordered_map<string, vector<string>> mp;
    unordered_map<string, bool> dead;
    string king;
    ThroneInheritance(string kingName) {
        king = kingName;
    }

    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead[name] = true;
    }

    void dfs(string cur, vector<string>& ord) {
        if (dead.find(cur) == dead.end()) ord.push_back(cur);
        if (mp.find(cur) == mp.end()) return;
        for (auto c : mp[cur]) {
            dfs(c, ord);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string> ret;
        dfs(king, ret);
        return ret;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */