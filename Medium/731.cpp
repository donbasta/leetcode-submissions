class MyCalendarTwo {
public:
    map<int, int> mp;
    MyCalendarTwo() {
        
    }

    bool book(int start, int end) {
        auto x = mp.upper_bound(start);
        if (x != mp.begin() && (--x)->second == 2) return false;
        x = mp.upper_bound(start);

        while (true) {
            if (x == mp.end() || x->first >= end) break;
            if (x->second == 2) return false;
            ++x;
        }

        x = mp.upper_bound(start);
        int la;
        if (x == mp.begin()) la = 0;
        else la = (--x)->second;
        mp[start] = la + 1;
        x = mp.upper_bound(start);

        while (true) {
            if (x == mp.end() || x->first >= end) break;
            la = x->second;
            x->second++;
            ++x;
        }
        if (!mp.count(end)) mp[end] = la;

        // for (auto x : mp) {
        //     cout << x.first << '-' << x.second << ' ';
        // }
        // cout << '\n';

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */