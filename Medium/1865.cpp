class FindSumPairs {
public:
    vector<int> nums1, nums2;
    map<int, int> cnt;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (auto e : nums2) cnt[e]++;
    }
    
    void add(int index, int val) {
        cnt[nums2[index]]--;
        nums2[index] += val;
        cnt[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (auto e : nums1) {
            if (cnt.count(tot - e)) ans += cnt[tot - e];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */