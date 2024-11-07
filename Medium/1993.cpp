class LockingTree {
public:
    vector<vector<int>> ch;
    vector<int> lk, par;
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        ch.resize(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) continue;
            ch[parent[i]].push_back(i);
        }
        lk.assign(n, -1);
        par = parent;
    }
    
    bool lock(int num, int user) {
        if (lk[num] != -1) return false;
        lk[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (lk[num] != user) return false;
        lk[num] = -1;
        return true;
    }

    bool upgrade(int num, int user) {
        bool ok = (lk[num] == -1);
        int cur = par[num];
        while (cur != -1) {
            ok &= (lk[cur] == -1);
            cur = par[cur];
        }
        if (!ok) return false;
        int cnt = 0;
        queue<int> Q;
        Q.emplace(num);
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto c : ch[now]) {
                if (lk[c] != -1) {
                    cnt++;
                    lk[c] = -1;
                }
                Q.push(c);
            }
        }
        if (cnt == 0) return false;
        lk[num] = user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */