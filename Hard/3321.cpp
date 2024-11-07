using ll = long long;

struct DS {
    set<pair<int, int>> s1, s2;
    unordered_map<int, int> cnt;
    ll sum = 0;
    int x;
    DS(int x) : x(x) {}
    void insert(int val, int mul) {
        for (int i = 0; i < mul; i++) {
            pair<int, int> cari = make_pair(-cnt[val], -val);
            if (s1.count(cari)) {
                s1.erase(cari);
                cnt[val]++;
                sum += val;
                s1.emplace(-cnt[val], -val);
            } else if (s2.count(cari)) {
                s2.erase(cari);
                cnt[val]++;
                s2.emplace(-cnt[val], -val);
            } else {
                cnt[val]++;
                if (s1.size() == x) {
                    s2.emplace(-cnt[val], -val);
                } else {
                    sum += val;
                    s1.emplace(-cnt[val], -val);
                }
            }
            if (!s2.empty() && (*s1.rbegin() > *s2.begin())) {
                auto p = *s1.rbegin(), q = *s2.begin();
                sum -= 1ll * p.first * p.second;
                sum += 1ll * q.first * q.second;
                s1.erase(p), s2.erase(q);
                s1.insert(q), s2.insert(p);
            }
        }
    }
    void remove(int val) {
        if (!cnt.count(val)) return;
        if (s1.count(make_pair(-cnt[val], -val))) {
            s1.erase(make_pair(-cnt[val], -val));
            sum -= 1ll * cnt[val] * val;
            cnt[val]--;
            if (!s2.empty() && make_pair(-cnt[val], -val) > *s2.begin()) {
                s1.insert(*s2.begin());
                sum += 1ll * s2.begin()->first * s2.begin()->second;
                s2.erase(s2.begin());
                if (cnt[val] > 0) s2.emplace(-cnt[val], -val);
            } else {
                if (cnt[val] > 0) {
                    s1.emplace(-cnt[val], -val);
                    sum += 1ll * cnt[val] * val;
                }
            }
            if (cnt[val] == 0) cnt.erase(val);
        } else {
            s2.erase(make_pair(-cnt[val], -val));
            cnt[val]--;
            if (cnt[val] > 0) s2.emplace(-cnt[val], -val);
            else cnt.erase(val);
        }
    }
    ll get_sum() {
        return sum;
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<ll> ans(n - k + 1);
        unordered_map<int, int> cnt;
        for (int i = 0; i < k; i++) {
            cnt[nums[i]]++;
        }
        DS ds(x);
        for (auto e : cnt) {
            ds.insert(e.first, e.second);
        }
        ans[0] = ds.get_sum();
        for (int i = 1; i <= n - k; i++) {
            ds.insert(nums[i + k - 1], 1);
            ds.remove(nums[i - 1]);
            ans[i] = ds.get_sum();
        }
        return ans;
    }
};