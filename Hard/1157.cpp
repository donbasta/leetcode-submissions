class MajorityChecker {
public:
    unordered_map<int, vector<int>> pos;
    vector<int> arr;

    MajorityChecker(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            pos[arr[i]].push_back(i);
        }
        this->arr = arr;
    }

    int random(int left, int right) {
        return (rand() % (right - left + 1)) + left;
    }
    
    int query(int left, int right, int threshold) {
        for (int i = 0; i < 20; i++) {
            int x = arr[random(left, right)];
            int b = upper_bound(pos[x].begin(), pos[x].end(), right) - pos[x].begin();
            int a = lower_bound(pos[x].begin(), pos[x].end(), left) - pos[x].begin();
            if (b - a >= threshold) return x;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */