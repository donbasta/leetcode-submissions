class OrderedStream {
public:
    vector<string> ve;
    int n, cur = 0;
    OrderedStream(int n) : n(n) {
        ve.resize(n);
    }
    
    vector<string> insert(int idKey, string value) {
        ve[idKey - 1] = value;
        vector<string> ret;
        while (cur < n && ve[cur] != "") {
            ret.push_back(ve[cur]);
            cur++;
        }
        return ret;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */