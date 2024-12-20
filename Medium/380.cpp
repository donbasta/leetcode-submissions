class RandomizedSet {
public:
    vector<int> data;
    unordered_map<int, int> idx;

    RandomizedSet() {
        
    }

    bool insert(int val) {
        if (idx.count(val)) return false;
        data.push_back(val);
        idx[val] = data.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!idx.count(val)) return false;
        idx[data.back()] = idx[val];
        swap(data.back(), data[idx[val]]);
        data.pop_back();
        idx.erase(val);
        return true;
    }

    int getRandom() {
        return data[rand() % (data.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */