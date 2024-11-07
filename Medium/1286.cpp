class CombinationIterator {
public:
    vector<int> idx, last;
    string ch;
    int len;
    CombinationIterator(string characters, int combinationLength) {
        idx.resize(combinationLength);
        iota(idx.begin(), idx.end(), 0);
        ch = characters;
        last.resize(combinationLength);
        int n = ch.size();
        for (int i = 0; i < combinationLength; i++) {
            last[i] = n - combinationLength + i;
        }
        len = combinationLength;
    }
    
    string next() {
        string ret;
        for (auto c : idx) ret.push_back(ch[c]);

        if (idx == last) {
            idx = vector<int>{-1};
        } else {
            int ptr = len - 1;
            while (ptr >= 0 && idx[ptr] == ptr + (int)ch.size() - len) ptr--;
            idx[ptr]++;
            for (int i = ptr + 1; i < len; i++) {
                idx[i] = idx[ptr] + i - ptr;
            }
        }
    
        return ret;
    }
    
    bool hasNext() {
        return idx != vector<int>{-1};
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */