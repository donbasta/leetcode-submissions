class Allocator {
public:
    vector<int> ve;
    Allocator(int n) {
        ve.assign(n, -1);
    }

    int allocate(int size, int mID) {
        int st = -1, len = 0;
        bool found = false;
        int n = ve.size();
        for (int i = 0; i < n; i++) {
            if (ve[i] != -1) {
                len = 0, st = -1;
            } else {
                if (st == -1) st = i;
                len++;
                if (len >= size) {
                    found = true;
                    break;
                }
            }
        }
        if (!found) return -1;
        for (int i = st; i < st + size; i++) {
            ve[i] = mID;
        }

        return st;
    }
    
    int free(int mID) {
        int x = 0;
        for (auto& e : ve) {
            if (e == mID) {
                x++;
                e = -1;
            }
        }
        return x;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */