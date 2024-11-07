class SnapshotArray {
public:
    int _snap = 0;
    vector<vector<pair<int, int>>> _ve;

    SnapshotArray(int length) {
        _ve.resize(length);
        for (int i = 0; i < length; i++) {
            _ve[i].emplace_back(-1, 0);
        }
    }
    
    void set(int index, int val) {
        _ve[index].emplace_back(_snap - 1, val);
    }
    
    int snap() {
        _snap++;
        return _snap - 1;
    }
    
    int get(int index, int snap_id) {
        int lmao = upper_bound(_ve[index].begin(), _ve[index].end(), make_pair(snap_id, -1)) - _ve[index].begin();
        --lmao;
        return _ve[index][lmao].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */