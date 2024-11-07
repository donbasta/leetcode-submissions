class BrowserHistory {
public:
    vector<string> his;
    int cur;

    BrowserHistory(string homepage) {
        his.push_back(homepage);
        cur = 0;
    }
    
    void visit(string url) {
        while (his.size() > cur + 1) his.pop_back();
        his.push_back(url);
        cur++;
    }
    
    string back(int steps) {
        cur = max(cur - steps, 0);
        return his[cur];
    }
    
    string forward(int steps) {
        cur = min(cur + steps, (int) his.size() - 1);
        return his[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */