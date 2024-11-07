class MovieRentingSystem {
public:
    set<pair<int, int>> ve[10005];
    map<int, int> mp[10005];
    set<vector<int>> cur;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        int mx = -1;
        for (auto e : entries) {
            mx = max(mx, e[1]);
        }
        for (auto e : entries) {
            ve[e[1]].emplace(e[2], e[0]);
            mp[e[1]][e[0]] = e[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ret;
        if (ve[movie].empty()) return ret;
        for (auto e : ve[movie]) {
            ret.push_back(e.second);
            if (ret.size() >= 5) break;
        }
        return ret;
    }
    
    void rent(int shop, int movie) {
        int price = mp[movie][shop];
        ve[movie].erase(make_pair(price, shop));
        cur.emplace(vector<int>{price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = mp[movie][shop];
        ve[movie].emplace(price, shop);
        cur.erase(vector<int>{price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ret;
        if (cur.empty()) return ret;
        for (auto e : cur) {
            ret.emplace_back(vector<int>{e[1], e[2]});
            if (ret.size() >= 5) break;
        }
        return ret;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */