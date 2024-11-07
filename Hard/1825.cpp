class MKAverage {
public:
    set<pair<int, int>> le, mid, ri;
    int _m, _k;
    long long totMid;
    vector<int> stream;
    
    MKAverage(int m, int k) {
        _m = m, _k = k, totMid = 0;
    }
    
    void addElement(int num) {
        stream.push_back(num);
        if (stream.size() == _m) {
            vector<pair<int, int>> tmp;
            for (int i = 0; i < _m; i++) tmp.emplace_back(stream[i], i);
            sort(tmp.begin(), tmp.end());
            for (int i = 0; i < _m; i++) {
                if (i < _k) le.insert(tmp[i]);
                else if (i < _m - _k) {
                    totMid += tmp[i].first;
                    mid.insert(tmp[i]);
                } else ri.insert(tmp[i]);
            }
        } else if (stream.size() > _m) {
            int idxToRemoveFromStream = stream.size() - (_m + 1);
            int curIdx = stream.size() - 1;
            pair<int, int> toRemove = make_pair(stream[idxToRemoveFromStream], idxToRemoveFromStream);
            pair<int, int> toInsert = make_pair(num, curIdx);
            if (le.find(toRemove) != le.end()) {
                le.erase(toRemove);
            } else if (mid.find(toRemove) != mid.end()) {
                totMid -= toRemove.first, mid.erase(toRemove);
                auto bigLe = le.end();
                --bigLe;
                mid.insert(*bigLe), totMid += bigLe->first;
                le.erase(bigLe);
            } else if (ri.find(toRemove) != ri.end()) {
                ri.erase(toRemove);
                auto bigMid = mid.end();
                --bigMid;
                ri.insert(*bigMid);
                totMid -= bigMid->first, mid.erase(bigMid);
                auto bigLe = le.end();
                --bigLe;
                totMid += bigLe->first, mid.insert(*bigLe);
                le.erase(bigLe);
            } else {
                assert(false);
            }

            auto lolMid = mid.begin();
            auto lolRight = ri.begin();
            if (num <= lolMid->first) {
                le.insert(toInsert);
            } else if (num <= lolRight->first) {
                le.insert(*lolMid);
                totMid -= lolMid->first;
                mid.erase(lolMid);
                totMid += num;
                mid.insert(toInsert);
            } else {
                le.insert(*lolMid);
                totMid -= lolMid->first;
                mid.erase(lolMid);
                totMid += lolRight->first;
                mid.insert(*lolRight);
                ri.erase(lolRight);
                ri.insert(toInsert);
            }
        }
    }
    
    int calculateMKAverage() {
        if (stream.size() < _m) return -1;
        return totMid / (_m - 2 * _k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */