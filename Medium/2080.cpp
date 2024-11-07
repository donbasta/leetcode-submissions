class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> pos;
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            pos[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if (pos.find(value) == pos.end()) return 0;
        return upper_bound(pos[value].begin(), pos[value].end(), right) - lower_bound(pos[value].begin(), pos[value].end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */